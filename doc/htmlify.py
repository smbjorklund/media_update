import sys
from markdown2 import markdown
import re
import os

def md_linkify(text, filename):
    text = re.sub(r'(\bJEW-\d+\b)', r'[\1](https://jira.uib.no/browse/\1)', text)
    text = re.sub(r'\bapidoc:(\w+(?:\.\w+)*(?:/[\w.-]+)?)', r'http://apidoc.app.uib.no/system/\1.html', text)

    def expand_date(m):
        p = os.popen("git log --pretty=format:%ci --max-count=1 " + filename, "r")
        date = p.read().split()
        return date[0]

    text = re.sub(r'\${DATE}', expand_date, text)

    return text

html  = open("tmpl/header.html").read().decode("UTF-8")
html += markdown(md_linkify(open(sys.argv[1]).read().decode("UTF-8"), sys.argv[1]))
html += open("tmpl/footer.html").read().decode("UTF-8")

print html.encode("UTF-8")

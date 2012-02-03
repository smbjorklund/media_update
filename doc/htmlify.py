import sys
from markdown2 import markdown
import re

def md_linkify(text):
    text = re.sub(r'(\bJEW-\d+\b)', r'[\1](https://jira.uib.no/browse/\1)', text)
    text = re.sub(r'\bapidoc:(\w+(?:\.\w+)*(?:/[\w.-]+)?)', r'http://apidoc.app.uib.no/system/\1.html', text)
    return text

html  = open("tmpl/header.html").read().decode("UTF-8")
html += markdown(md_linkify(open(sys.argv[1]).read().decode("UTF-8")))
html += open("tmpl/footer.html").read().decode("UTF-8")

import os
host = os.environ.get("WWW_UIB_NO")
if host:
    html = re.sub("https?://www\.uib\.no", "http://" + host, html)

print html.encode("UTF-8")

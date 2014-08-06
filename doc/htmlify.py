import sys
from markdown2 import markdown
import re
import os

def md_expand(text, filename):
    text = re.sub(r'(\bJEW-\d+\b)', r'[\1](https://jira.uib.no/browse/\1)', text)
    text = re.sub(r'(\bPI-(\d+)\b)', r'[\1](http://prosjekt.uib.no/issues/\2)', text)
    text = re.sub(r'(\bBS-(\d+)\b)', r'[\1](https://bs.uib.no/?module=issues&action=view&tid=\2)', text)
    text = re.sub(r'((?:\bRTS-|#)(\d+)\b)', r'[\1](https://rts.uib.no/issues/\2)', text)
    text = re.sub(r'\bapidoc:(\w+(?:\.\w+)*(?:/[\w.-]+)?)', r'http://apidoc.app.uib.no/system/\1.html', text)

    def expand_date(m):
        p = os.popen("git log --pretty=format:%ci --max-count=1 " + filename, "r")
        date = p.read().split()
        return date[0]
    text = re.sub(r'\${DATE}', expand_date, text)

    def expand_date_version(m):
        date = None
        count = 0
        p = os.popen("git log --pretty=format:%ci --max-count=20 " + filename, "r")
        for line in p:
            d = line.split()[0]
            if date is None:
                date = d
                count = 1
            elif date == d:
                count += 1
            else:
                break
        version = date
        if count > 1:
            version += "-r" + str(count)
        return version
    text = re.sub(r'\${DATE_VERSION}', expand_date_version, text)

    return text

html  = open("tmpl/header.html").read().decode("UTF-8").replace("PAGE-ID", sys.argv[1].replace('.md', '').replace('/', '-'))
html += markdown(md_expand(open(sys.argv[1]).read().decode("UTF-8"), sys.argv[1]))
html += open("tmpl/footer.html").read().decode("UTF-8")

print html.encode("UTF-8")

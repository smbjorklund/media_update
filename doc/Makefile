HTML = \
       index.html    \
       hints.html  \
       spec.html     \
       style.html    \
       apache-local.html \
       render-array.html \
       blocks.html   \
       repo.html     \
       repo-readme.html  \
       release1.html \
       area.html \
       mockups/index.html \
       terms.html

PYTHON = python
PERL = perl
BOOTSTRAP_PY = bootstrap.py

.SUFFIXES: .md .html
.PHONY: clean realclean

.md.html:
	bin/python htmlify.py $< >$@

all: bin/python $(HTML)

mockups/index.html: mockups/mkindex
	$(PERL) mockups/mkindex

bin/python: bin/buildout
	bin/buildout

bin/buildout: $(BOOTSTRAP_PY)
	$(PYTHON) $(BOOTSTRAP_PY)

clean:
	rm -f $(HTML)

realclean: clean
	rm -f bin/buildout bin/python
	-rmdir bin
	rm -rf .installed.cfg develop-eggs parts

HTML = \
       index.html    \
       migrate.html  \
       spec.html     \
       style.html    \
       apache-local.html \
       render-array.html \
       blocks.html   \
       terms.html

PYTHON = python
BOOTSTRAP_PY = bootstrap.py

.SUFFIXES: .md .html
.PHONY: clean realclean

.md.html:
	bin/python htmlify.py $< >$@

all: bin/python $(HTML)

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

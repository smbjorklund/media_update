HTML = \
       cms.html      \
       datamodel-intro.html \
       fs.html       \
       fs_debugging_tips.html \
       howto.html    \
       git.html      \
       index.html    \
       lang.html     \
       meny.html     \
       notation.html \
       sebra.html    \
       terms.html    \
       style.html

PYTHON = python
BOOTSTRAP_PY = ../thesite-dev/bootstrap.py

.SUFFIXES: .txt .html
.PHONY: clean realclean

.txt.html:
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

HTML = \
  apache-local.html \
  area.html \
  blocks.html \
  course_site-w3-kurs.uib.no.html \
  drupal-deploy.html \
  drupal-sync-course-site.html \
  drupal-update.html \
  hints.html \
  index.html \
  release1.html \
  render-array.html \
  repo-readme.html \
  repo.html \
  server-setup.html \
  spec.html \
  style.html \
  terms.html \
  w3_server_layout.html \
  local-production.html \

PYTHON = python
PERL = perl
BOOTSTRAP_PY = bootstrap.py

.SUFFIXES: .md .html
.PHONY: makefile clean realclean

.md.html:
	bin/python htmlify.py $< >$@

all: bin/python $(HTML)

mockups/index.html: mockups/mkindex
	$(PERL) mockups/mkindex

bin/python: bin/buildout
	bin/buildout

bin/buildout: $(BOOTSTRAP_PY)
	$(PYTHON) $(BOOTSTRAP_PY)

makefile:
	$(PERL) update-makefile.pl >Makefile.new
	mv Makefile.new Makefile

clean:
	rm -f $(HTML)

realclean: clean
	rm -f bin/buildout bin/python
	-rmdir bin
	rm -rf .installed.cfg develop-eggs parts

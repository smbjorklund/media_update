HTML = \
  area.html \
  blocks.html \
  course_site-w3-kurs.uib.no.html \
  development-setup.html \
  drupal-deploy.html \
  drupal-sync-course-site.html \
  drupal-update.html \
  git.html \
  hints.html \
  index.html \
  local-production.html \
  release1.html \
  render-array.html \
  repo-readme.html \
  repo.html \
  server-setup.html \
  spec.html \
  style.html \
  terms.html \
  w3_server_layout.html \

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
	touch $@

bin/buildout: $(BOOTSTRAP_PY)
	$(PYTHON) $(BOOTSTRAP_PY)
	touch $@

makefile:
	$(PERL) update-makefile.pl >Makefile.new
	mv Makefile.new Makefile

clean:
	rm -f $(HTML)

realclean: clean
	rm -f bin/buildout bin/python
	-rmdir bin
	rm -rf .installed.cfg develop-eggs parts

ACLOCAL_AMFLAGS = -I m4

#SUBDIRS = test

bin_PROGRAMS = fillup
fillup_SOURCES = \
	src/consume.c \
	src/consume.h \
	src/dump.c \
	src/dump.h \
	src/file.c \
	src/file.h \
	src/fillup_cfg.c \
	src/fillup_cfg.h \
	src/getArguments.c \
	src/getArguments.h \
	src/metadata.c \
	src/metadata.h \
	src/parameters.c \
	src/parameters.h \
	src/parser.c \
	src/parser.h \
	src/portab.h \
	src/services.c \
	src/services.h \
	src/validate.c \
	src/validate.h \
	src/variableblock.c \
	src/variableblock.h

if WITH_LIBCMIS_MAN
fillup.8: man/fillup.xml
	$(DOCBOOK2MAN) $<

install-man: fillup.8
	mkdir -p $(DESTDIR)$(mandir)/man8/
	$(INSTALL_DATA) fillup.8 $(DESTDIR)$(mandir)/man8/

uninstall-man:
	-rm -rf $(DESTDIR)$(mandir)/man8/
endif

dist_man_MANS = man/fillup.xml

EXTRA_DIST = \
	$(dist_man_MANS) \
	LICENSE \
	README.md \
	autogen.sh

distclean-local:
	rm -rf *.cache *~ *.out *.pc fillup.8

dist-hook:
	git log --date=short --pretty="format:@%cd  %an  <%ae>  [%H]%n%n%s%n%n%e%b" | sed -e "s|^\([^@]\)|\t\1|" -e "s|^@||" >$(distdir)/ChangeLog


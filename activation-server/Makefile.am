
NULL=
man_MANS = bonobo-activation-server.1

bin_PROGRAMS=activation-client
libexec_PROGRAMS=bonobo-activation-server
noinst_PROGRAMS=test-performance

INCLUDES=					\
	-I$(top_srcdir) 			\
	-I$(top_builddir) 			\
	-I$(top_builddir)/bonobo-activation	\
	-I$(top_srcdir)/bonobo-activation	\
	-DPREFIX=\""$(prefix)"\"		\
	-DSERVERINFODIR=\"$(libdir)/bonobo/servers\" \
        -DSERVER_LOCALEDIR=\""${prefix}/${DATADIRNAME}/locale"\" \
	$(SERVER_CFLAGS)			\
	$(WARN_CFLAGS)				\
	-DSERVER_CONFDIR=\"$(sysconfdir)\"	\
	-DG_LOG_DOMAIN=\"Bonobo-Activation-Server\" \
	$(NULL)

bonobo_activation_server_SOURCES=				\
	activation-server-corba-extensions.c			\
	activation-server-corba-extensions.h			\
	activation-context.h					\
	activation-context-query.h				\
	activation-context-query.c				\
	activation-context-query-lexer.c			\
	activation-context-query-parser.c			\
	activation-context-query-parser.h			\
	activation-context-corba.c				\
	object-directory.h					\
	object-directory-corba.c				\
	object-directory-load.c					\
	object-directory-activate.c				\
	object-directory-config-file.c				\
	object-directory-config-file.h				\
	activation-server-main.c				\
	server.h

if OS_WIN32
bonobo_activation_server_LDFLAGS = -mwindows
endif

LDADD= \
	$(top_builddir)/bonobo/libbonobo-2.la \
	$(top_builddir)/bonobo-activation/libbonobo-activation.la \
	 -lname-server-2 $(SERVER_LIBS) @INTLLIBS@

activation_client_SOURCES=client.c

test_performance_SOURCES =	\
	test-performance.c	\
	object-directory-load.c	\
	server.h

TESTS=test-performance

serverinfodir=$(libdir)/bonobo/servers
$(server_in_file): $(server_in_file).in
	$(AM_V_GEN) $(SED) -e "s|\@LIBEXECDIR\@|$(libexecdir)|" $< > $@
server_in_file = Bonobo_CosNaming_NamingContext.server.in
serverinfo_DATA = $(server_in_file:.server.in=.server)

@INTLTOOL_SERVER_RULE@

EXTRA_DIST=activation-context-query-lexer.l activation-context-query-parser.y \
	$(server_in_file).in $(serverinfo_DATA)	\
	$(man_MANS) AUTHORS

YFLAGS = -d -v

activation-context-query-lexer.c: $(srcdir)/activation-context-query-lexer.l activation-context-query-parser.h
	$(AM_V_GEN) rm -f $@ && \
	$(LEX) -t $(srcdir)/activation-context-query-lexer.l >$@

stamp-parser: $(srcdir)/activation-context-query-parser.y
	$(AM_V_GEN) $(YACC) $(YFLAGS) $(srcdir)/activation-context-query-parser.y && \
	rm -f y.output && \
	touch $@

activation-context-query-parser.c: stamp-parser
	$(AM_V_GEN) test -f y.tab.c && mv -f y.tab.c activation-context-query-parser.c || touch $@

activation-context-query-parser.h: stamp-parser
	$(AM_V_GEN) test -f y.tab.h && mv -f y.tab.h activation-context-query-parser.h || touch $@

BUILT_SOURCES= activation-context-query-lexer.c activation-context-query-parser.c \
	activation-context-query-parser.h Bonobo_CosNaming_NamingContext.server

CLEANFILES=stamp-parser $(server_in_file) $(serverinfo_DATA) $(BUILT_SOURCES)

dist-hook:
	cd $(distdir) ; rm -f $(CLEANFILES)

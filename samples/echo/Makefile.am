#
# Makefile for the sample Echo server/client Bonobo components.
#

server_dot_in=Bonobo_Sample_Echo.server.in

$(server_dot_in): $(server_dot_in).in
	$(AM_V_GEN) $(SED) -e "s|\@libdir\@|$(libdir)|" $< > $@

samplesdir = $(libdir)/bonobo/samples
samples_PROGRAMS = bonobo-echo-2

bin_PROGRAMS     = echo-client-2
noinst_LIBRARIES = libEcho.a

bonobo_echo_2_SOURCES =		\
	main.c			\
	echo.c			\
	echo.h

bonobo_echo_2_LDADD =				\
	libEcho.a				\
	$(top_builddir)/bonobo/libbonobo-2.la	\
	$(top_builddir)/bonobo-activation/libbonobo-activation.la \
	$(LIBBONOBO_LIBS)			\
	$(INTLLIBS)

echo_client_2_SOURCES = echo-client.c
echo_client_2_LDADD =				\
	libEcho.a				\
	$(top_builddir)/bonobo/libbonobo-2.la	\
	$(top_builddir)/bonobo-activation/libbonobo-activation.la \
	$(LIBBONOBO_LIBS)			\
	$(INTLLIBS)

ECHO_CORBA_GENERATED =				\
	Bonobo_Sample_Echo-common.c		\
	Bonobo_Sample_Echo-skels.c		\
	Bonobo_Sample_Echo-stubs.c		\
	Bonobo_Sample_Echo.h

libEcho_a_SOURCES = $(ECHO_CORBA_GENERATED)

$(ECHO_CORBA_GENERATED): Bonobo_Sample_Echo.idl $(ORBIT_IDL)
	$(AM_V_GEN) $(ORBIT_IDL) -I$(top_srcdir)/idl $(srcdir)/Bonobo_Sample_Echo.idl

serverdir = $(libdir)/bonobo/servers
server_in_files = $(server_dot_in)
server_DATA = $(server_in_files:.server.in=.server)

@INTLTOOL_SERVER_RULE@

idldir    = $(datadir)/idl/bonobo-2.0
idl_DATA  = Bonobo_Sample_Echo.idl

EXTRA_DIST = $(server_DATA) $(idl_DATA) $(server_dot_in).in

INCLUDES = 						\
        -DGNOMELOCALEDIR=\""$(datadir)/locale"\"        \
	-DG_LOG_DOMAIN=\"Echo\"				\
	-I$(top_srcdir) 				\
	$(LIBBONOBO_CFLAGS)				\
	$(DISABLE_DEPRECATED_CFLAGS)			\
	$(WARN_CFLAGS)

CLEANFILES =  $(server_dot_in) $(server_DATA)


## Process this file with automake to produce Makefile.in

module = real_to_v

AM_CPPFLAGS = \
	-I$(top_srcdir)/src/include \
	-I$(top_srcdir)/src/xspice/cm

module_ldadd = cfunc.lo ifspec.lo

BUILT_SOURCES = cfunc.c ifspec.c
CLEANFILES = cfunc.c ifspec.c $(module).cm

all-local: $(module).cm

$(module).cm: $(module_ldadd)
	$(CC) $(CFLAGS) $(AM_CFLAGS) $(LDFLAGS) -shared -o $@ .libs/cfunc.o .libs/ifspec.o

ifspec.c: ifspec.ifs $(CMPP)
	CMPP_IDIR=$(srcdir) CMPP_ODIR=$(builddir) $(CMPP) -ifs

cfunc.c: cfunc.mod $(CMPP)
	CMPP_IDIR=$(srcdir) CMPP_ODIR=$(builddir) $(CMPP) -mod

run: $(module).cm
	$(top_builddir)/src/ngspice$(EXEEXT) -b $(srcdir)/$(module).cir

.PHONY: run all-local

MAINTAINERCLEANFILES = Makefile.in

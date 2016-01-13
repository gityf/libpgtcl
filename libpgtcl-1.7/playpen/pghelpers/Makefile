#
#
# $Id: Makefile,v 1.1 2008/11/05 17:34:49 karl Exp $
#

FILES= postgres-helpers.tcl
INSTALLDIR= /usr/local/lib/sc_postgres

all:	pkgIndex.tcl

pkgIndex.tcl:	$(FILES)
	echo 'pkg_mkIndex -verbose -- .' | tclsh8.4


install:	all
	mkdir -p $(INSTALLDIR)
	cp $(FILES) pkgIndex.tcl $(INSTALLDIR)

clean:
	rm -f pkgIndex.tcl

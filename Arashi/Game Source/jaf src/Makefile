
LIBNAME=$(shell basename $(shell pwd))
LDNAME=lib$(LIBNAME)_static.a

####################################################################
# Makefile
####################################################################

PATH_TO_BASE=..

include $(PATH_TO_BASE)/../Makefile.target
include $(PATH_TO_BASE)/../Makefile.common

#LIBS=
#EXTRA_FLAGS=-DNSYS_X11=1 -I/usr/X11R6.3/include
#EXTRA_LDFLAGS=/usr/X11R6.3/lib/X11.framework/X11

#EXTRA_FLAGS=-m32
#EXTRA_LDFLAGS=-m32

#EXTRA_INCS=-I$(PATH_TO_BASE) -I..
#EXTRA_LIBS=-L$(PATH_TO_BASE) -l$(LIBNAME)_static


####################################################################
# Our objects 
####################################################################

DIRS=$(wildcard */)
#OBJS=$(subst .cpp,.$(OFILE),$(wildcard */*.cpp))
OBJS=$(subst .c,.$(OFILE),$(wildcard *.c))
#OTHEROBJS=$(subst .cpp,.$(OFILE),$(wildcard ../*/*.cpp))

####################################################################
# The libraries and programs 
####################################################################

SIMPLE_PROGRAMS1=
SIMPLE_PROGRAMS2=
SIMPLE_PROGRAMS3=
SIMPLE_PROGRAMS=$(SIMPLE_PROGRAMS1) $(SIMPLE_PROGRAMS2) $(SIMPLE_PROGRAMS3)
PROGRAMS=$(SIMPLE_PROGRAMS)


####################################################################
# The targets 
####################################################################

all:
	make $(OBJS)
#	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) all;)
#	$(MAKE) $(LDNAME)
#	$(MAKE) -i $(PROGRAMS)


all_libs: base_libs


base_libs:


$(LDNAME):	$(OBJS) $(OTHEROBJS)
	$(AR_CMD) $(OBJS) $(OTHEROBJS)
	$(RANLIB_CMD) $(LDNAME) 


clean:
	rm -rf debug.html */debug.html */debug.htm debug.txt */debug.txt ndebug.txt */ndebug.txt adebug.txt */adebug.txt *.o *.obj *.OBJ *.lib *.a *.s *.bak *.log map.f build *Data *.pdb *.lib *.bak $(PROGRAMS) *.html *.exe *.EXE *.exe.so *68k *.SYM .DS_Store *.ilk *.app *.class .gdb_history .nautilus-metafile.xml */*Data */Debug */*.ncb */*/Debug Debug */build resource.frk RESOURCE.FRK finder.dat FINDER.DAT ._* */._* */*/._* */*/*/._* *~ */*~ */*/*~ */*/*/*~ PaxHeader
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) clean;)


fix: fix_perm fix_type
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) fix;)


# The different Libraries and Programs...


# dependencies
# NOTE: it's ok to see errors when running makedepend
depend:
	makedepend $(DEPENDFLAGS) *.c
	makedepend $(DEPENDFLAGS) *.cpp
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) depend;)


remove_depends:
	rm -f Makefile.dep
	touch Makefile.dep
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -ik -C $(DIR) remove_depends;)


include $(PATH_TO_BASE)/../Makefile.tail

include Makefile.dep


# DO NOT DELETE

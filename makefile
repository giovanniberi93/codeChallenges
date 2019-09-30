SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)
$(SUBDIRS):
        $(MAKE) -C $@

clean: $(SUBDIRS)
$(SUBDIRS):
		make clean -C 

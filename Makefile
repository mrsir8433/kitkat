TOPTARGETS := all clean

SUBDIRS := engine testbed

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

run:
	./bin/testbed.exe
.PHONY: $(TOPTARGETS) $(SUBDIRS) run
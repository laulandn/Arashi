
####################################################################
# Makefile
####################################################################

DIRS=$(wildcard */)


####################################################################
# The targets 
####################################################################

all:
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) all;)

#configure:
#	$(foreach DIR,$(DIRS), cd $(DIR).;)

clean:
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) clean;)
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) remove_depends;)

fix:
	chmod +x conf* */conf*
#	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) fix;)

touch:
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) touch;)

depend: remove_depends
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) depend;)

remove_depends:
	$(foreach DIR,$(DIRS),$(MAKE) -ik -C $(DIR) remove_depends;)


# DO NOT DELETE

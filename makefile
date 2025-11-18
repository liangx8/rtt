MCUS=f421
all:$(MCUS)


define CREATE_BUILD_TARGET
$1:
	$(MAKE) -f target.mk TARGET=$1
endef
$(foreach TGT,$(MCUS),$(eval $(call CREATE_BUILD_TARGET,$(TGT))))


clean:
	rm -rf obj
	find -name \*~ -or -name \*.o -exec rm \{} \;

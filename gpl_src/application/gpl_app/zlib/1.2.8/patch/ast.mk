##
## Copyright (c) 2004-2012
## ASPEED Technology Inc. All Rights Reserved
## Proprietary and Confidential
##
## By using this code you acknowledge that you have signed and accepted
## the terms of the ASPEED SDK license agreement.
##
include $(AST_SDK_ROOT)/ast.cfg

TARGET_FOLDER_NAME=$(TARGET)-$(CONFIG)

PREFIX=$(AST_SDK_ROOT)/build/$(TARGET_FOLDER_NAME)/prefix
ROOTFS=$(AST_SDK_ROOT)/build/$(TARGET_FOLDER_NAME)/rootfs_addon


default:
	make -f ast.mk clean
	make -f ast.mk config
	make -f ast.mk build
	make -f ast.mk install

config:
	CROSS_PREFIX=$(CROSS_COMPILE) ./configure --prefix=$(PREFIX)

build:
	make
	make install

install:
	# Now copy files to rootfs
	@echo 'copy files...'
	@mkdir -p $(ROOTFS)/lib
	@mkdir -p $(ROOTFS)/bin

	@cp -af $(PREFIX)/lib/libz.so.* $(ROOTFS)/lib
	#@cp -f $(PREFIX)/bin/xmlwf $(ROOTFS)/bin

clean:
	[ -f Makefile ] && make distclean || echo "Nothing to clean"


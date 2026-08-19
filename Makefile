TOP = $(CURDIR)
TMAKE_DIR = $(TOP)/make
include $(TMAKE_DIR)/tmake-init.mk

SUBDIRS = tgui-clock
include $(TMAKE_DIR)/tmake-subdir.mk 

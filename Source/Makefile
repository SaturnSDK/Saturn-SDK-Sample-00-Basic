# SEGA Saturn SDK // Sample 00 - Basic [Makefile]
.SILENT:

ifndef TOPDIR
export TOPDIR		:= $(shell cd ../ && pwd)
export TOPSRC		= $(TOPDIR)/Source
export TARGETDIR	= $(TOPDIR)/Bin
export OBJDIR		= $(TOPDIR)/Obj/$(BUILD)
endif

SOURCEDIR	= Source
ISO	?= False

PROJECT	:= Basic
TARGET	:= $(PROJECT)
OUTFILE	= $(TARGETDIR)/$(TARGET)

CROSS_COMPILE=$(SATURN_ROOT)/toolchain_elf/bin/saturn-sh2-elf-

CC=$(CROSS_COMPILE)gcc
AS=$(CROSS_COMPILE)as
LD=$(CROSS_COMPILE)ld
OBJCOPY=$(CROSS_COMPILE)objcopy
MAKE=$(SATURN_ROOT)/toolchain/bin/saturn-make

CFLAGS = -m2

ifeq ($(DEVCART),True)
CFLAGS += -DBUILD_USBDEVCART
endif

LDFLAGS = -m2 -Xlinker -T$(TOPSRC)/Saturn.lnk \
	-Xlinker -Map -Xlinker $(TARGETDIR)/$(TARGET).map \
	-nostartfiles

debug:	BUILD = Debug
debug:	BUILD_TYPE = debug
debug:	BUILD_DEF = DEBUG
debug:	TARGET := $(TARGET)D
debug:	CFLAGS	+= -g
debug:	$(TARGET)

release: BUILD = Release
release: BUILD_TYPE = release
release: BUILD_DEF = RELEASE
release: TARGET := $(TARGET)
release: LDFLAGS += -Xlinker --strip-debug
release: $(TARGET)

ifneq ($(OBJDIR), $(CURDIR))
$(TARGETDIR):
	mkdir -p $(TARGETDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

CFILES	:= $(foreach dir,$(SOURCEDIR),$(notdir $(wildcard $(dir)/*.c)))
# Ignore the crt files from the object files
ASFILES	:= $(foreach dir,$(SOURCEDIR),$(notdir $(filter-out $(dir)/$(wildcard crt*.s), $(wildcard $(dir)/*.s))))
export VPATH	:= $(foreach dir,$(SOURCEDIR),$(CURDIR)/$(dir))
export OBJS		:= $(CFILES:.c=.o) $(ASFILES:.s=.o)
# VPATH should allow the crt*.s files to be picked up (assuming they have not been moved)
export CRTOBJS	:= crt0.o

$(TARGET): $(OBJDIR) $(TARGETDIR)
	$(MAKE) -C $(OBJDIR) -f $(TOPSRC)/Makefile $(BUILD_TYPE)
	# This seems a lot less elegant than I'd like
ifeq ($(ISO),True)
	# Thanks, The Rockin'-B
	mkdir -p $(TARGETDIR)/CD
	echo "ABSTRACT" > $(TARGETDIR)/CD/ABS.TXT
	echo "BIBLIOGRAPHY" > $(TARGETDIR)/CD/BIB.TXT
	echo "COPYRIGHT" > $(TARGETDIR)/CD/CPY.TXT
	cp $(OUTFILE).bin $(TARGETDIR)/CD/0.BIN
	printf "Making ISO\n"
	mkisofs -quiet -sysid "SEGA SATURN" -volid "SaturnApp" \
	-volset "SaturnApp" -publisher "SEGA ENTERPRISES, LTD." \
	-preparer "SEGA ENTERPRISES, LTD." -appid "SaturnApp" \
	-abstract "ABS.TXT" -copyright "CPY.TXT" -biblio "BIB.TXT" \
	-generic-boot IP.BIN -full-iso9660-filenames \
	-o $(OUTFILE).iso $(TARGETDIR)/CD
endif

else

$(TARGET): $(CRTOBJS) $(OBJS)
	printf "Linking: $(OUTFILE) ... "
	$(CC) -o $(OUTFILE) $(LDFLAGS) $(CRTOBJS) $(OBJS)
	printf "Done\n"
	printf "Converting $(OUTFILE) to $(OUTFILE).bin ... "
	$(OBJCOPY) -O binary $(OUTFILE) $(OUTFILE).bin
	printf "Done\n"

%.o: %.c
	printf "Compiling: $< ... "
	$(CC) -MMD -MP -MF $*.d $(CFLAGS) -c $< -o $@
	printf "Done\n"

%.o: %.s
	printf "Assembling: $< ... "
	$(AS) $< -o $@
	printf "Done\n"

-include $(OBJDIR)/*.d

endif

.PHONY: clean iso

clean:
	printf "Removing $(TARGETDIR) ... "
	rm -rf $(TARGETDIR)
	printf "Done\n"
	printf "Removing $(OBJDIR) ... "
	rm -rf $(OBJDIR)
	printf "Done\n"


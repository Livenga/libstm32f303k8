EABI   = arm-none-eabi
CC 	   = $(EABI)-gcc
AR     = $(EABI)-ar

PRJC   = libstm32f303k8.a
OBJDIR = objs


SRC  		= $(shell find src/ -name \*.c)
OBJS 	  = $(addprefix $(OBJDIR)/, $(patsubst %.c,%.o,$(SRC)))
OBJSDIR = $(sort $(dir $(OBJS)))

CPU = cortex-m4

ARM_OPTIONS =
ARM_OPTIONS += -mcpu=$(CPU)
ARM_OPTIONS += -mtune=$(CPU)
#ARM_OPTIONS += -march=armv7-a
ARM_OPTIONS += -mfloat-abi=softfp
ARM_OPTIONS += -mfpu=fpv4-sp-d16

default:
	[ -d  $(OBJDIR)   ] || mkdir -v $(OBJDIR)
	[ -d "$(OBJSDIR)" ] || mkdir -pv $(OBJSDIR)
	make $(PRJC)

$(PRJC):$(OBJS)
	$(AR) rcs $@ $^

$(OBJDIR)/%.o:%.c
	$(CC) -o $@ -c $< \
		$(ARM_OPTIONS) \
		-O2

clean:
	[ ! -d $(PRJC) ] || rm -v libstm32f303.a
	[ ! -d $(OBJDIR) ] || rm -rv $(OBJDIR)

all:
	make clean default


.PHONY: test
test:
	make -C test -f Makefile

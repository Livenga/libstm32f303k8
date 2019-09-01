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
ARM_OPTIONS += -T ../stm32f303k8.ld
ARM_OPTIONS += -specs=nano.specs
ARM_OPTIONS += -mcpu=$(CPU)
ARM_OPTIONS += -mtune=$(CPU)
ARM_OPTIONS += -march=armv7e-m
ARM_OPTIONS += -mfloat-abi=hard
ARM_OPTIONS += -mfpu=fpv4-sp-d16
ARM_OPTIONS += -mthumb

default:
	[ -d  $(OBJDIR)   ] || mkdir -v $(OBJDIR)
	[ -d "$(OBJSDIR)" ] || mkdir -pv $(OBJSDIR)
	make $(PRJC)

$(PRJC):$(OBJS)
	$(AR) rcs $@ $^

$(OBJDIR)/%.o:%.c
	$(CC) -o $@ -c $< $(ARM_OPTIONS)

clean:
	[ ! -d $(PRJC) ] || rm -v libstm32f303.a
	[ ! -d $(OBJDIR) ] || rm -rv $(OBJDIR)

all:
	make clean default


.PHONY: test
test:
	make -C test -f Makefile

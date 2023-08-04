TARGET = main

MCU ?= STM32F303K8

MCU_FILES = STM32F303K8T6
MCU_CLASS = F3

# Define the linker script location and chip architecture.
LD_SCRIPT = $(MCU_FILES).ld
MCU_SPEC = cortex-m4


# Toolchain definitions (ARM bare metal defaults)
TOOLCHAIN =
CC = $(TOOLCHAIN)arm-none-eabi-gcc
AS = $(TOOLCHAIN)arm-none-eabi-as
LD = $(TOOLCHAIN)arm-none-eabi-ld
OC = $(TOOLCHAIN)arm-none-eabi-objcopy
OD = $(TOOLCHAIN)arm-none-eabi-objdump
OS = $(TOOLCHAIN)arm-none-eabi-size

# Assembly directives.
ASFLAGS += -c
ASFLAGS += -O0
ASFLAGS += -mcpu=$(MCU_SPEC)
ASFLAGS += -mthumb
ASFLAGS += -Wall
# (Set error messages to appear on a single line.)
ASFLAGS += -fmessage-length=0

# C compilation directives
CFLAGS += -mcpu=$(MCU_SPEC)
CFLAGS += -mthumb
CFLAGS += -Wall
CFLAGS += -g
# (Set error messages to appear on a single line.)
CFLAGS += -fmessage-length=0
# (Set system to ignore semihosted junk)
CFLAGS += --specs=nosys.specs

# Linker directives.
LSCRIPT = ./startup/$(LD_SCRIPT)
LFLAGS += -mcpu=$(MCU_SPEC)
LFLAGS += -mthumb
LFLAGS += -Wall
LFLAGS += --specs=nosys.specs
LFLAGS += -nostdlib
LFLAGS += -lgcc
LFLAGS += -T$(LSCRIPT)

AS_SRC   =  ./startup/$(MCU_FILES)_core.S
C_SRC    =  ./source/main.c
C_SRC    += ./source/system.c
C_SRC    += ./source/nvic.c
C_SRC    += ./source/ui.c
#C_SRC    += ./device/system_stm32f3xx.c

INCLUDE  =  -I./
INCLUDE  += -I./device/
INCLUDE  += -I./include/
INCLUDE  += -I./source/
INCLUDE  += -I./source/include/

OBJS  = $(AS_SRC:.S=.o)
OBJS += $(C_SRC:.c=.o)

.PHONY: all
all: $(TARGET).bin

%.o: %.S
	$(CC) -x assembler-with-cpp $(ASFLAGS) $< -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OC) -S -O binary $< $@
	$(OS) $<

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(TARGET).elf
	rm -f $(TARGET).bin

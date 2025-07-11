#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
# PLATFORM =        Not hardcoring the value cmd will andle such as make bulild PLATFORM = HOST OR make build PLATFORM = MSP432 

# Architectures Specific Flags
TARGET = c2m2.out
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
FPU = fpv4-sp-d16
FLOAT-ABI = hard
SPECS = --specs=nosys.specs

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	LDFLAGS = 
	PLATFORM_DEFINES = -DHOST
else 
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 \
		-mcpu=$(CPU) -mthumb -march=$(ARCH) \
		-mfloat-abi=$(FLOAT-ABI) -mfpu=$(FPU)
	LDFLAGS = -T $(LINKER_FILE) $(SPECS)
	PLATFORM_DEFINES = -DMSP432

endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET) *.i *.asm *.map
# Deletes all build output files.


.PHONY: compile-all
compile-all: $(OBJS)
# Compiles all .o files but does NOT link.


.PHONY: build
build: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(OBJS) $(CFLAGS) $(LDFLAGS) -Wl,-Map=$(TARGET:.out=.map) -o $@
	size $@
# Links all object files into c1m2.out. Also generates .map and prints binary size.



%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(PLATFORM_DEFINES) $(INCLUDES) -MMD
# Compiles .c to .o and creates .d files for dependency tracking.

%.i: %.c
	$(CC) -E $< $(CFLAGS) $(PLATFORM_DEFINES) $(INCLUDES) -o $@
# Generates .i (preprocessed output)

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(PLATFORM_DEFINES) $(INCLUDES) -o $@
# Compiles to assembly file

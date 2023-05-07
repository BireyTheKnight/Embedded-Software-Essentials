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
# Makefile that support two platform targets which are the host enviroment and
# embedded system MSP432
#
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Generate the object file for all c-source files but
#                 do not link
#      <FILE>.i - Generate the preprocessed output of all c-program
#                 implementation files
#      <FILE>.asm - Generate assembly output of c-program implementation 
#                   files and the final output executable
#      compile-all - Compile all object files, but do not link
#      build - Compile all object files and link into a final executable
#      clean - Remove all compiled objects, preprocessed outputs, assembly
#              outputs, executable files and build output files
#
# Platform Overrides:
#      PLATFORM - The target platform to compile for (HOST, MSP432)
#
#------------------------------------------------------------------------------
include sources.mk


TARGET_NAME = c1m2
TARGET = $(TARGET_NAME).out


# Architectures Specific Flags
ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	FLOAT_ABI = hard
	FPU = fpv4-sp-d16
endif


# Compiler Flags and Defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET_NAME).map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mthumb \
		 -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU) -Wall -Werror\
		 $(addprefix -I, $(INCLUDES)) -g -O0 -std=c99 
	CPPFLAGS = -MD
	PLATFORM_TARGET = -DMSP432

else ifeq ($(PLATFORM), HOST)
	CC = gcc
	LDFLAGS = -Wl,-Map=$(TARGET_NAME).map
	CFLAGS = $(addprefix -I, $(INCLUDES)) -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -MD
	PLATFORM_TARGET =-DHOST
endif


OBJS = $(SOURCES:.c=.o)

ASMS = $(SOURCES:.c=.asm)

PPOS = $(SOURCES:.c=.i)

DEPS = $(SOURCES:.c=.d)


%.i : %.c
	$(CC) -E $< $(CFLAGS) -o $@ \
	$(PLATFORM_TARGET) 


%.asm : %.c
	$(CC) -S $< $(CFLAGS) \
	$(PLATFORM_TARGET) -o $@


ifeq ($(MAKECMDGOALS),$(TARGET_NAME).asm)

$(TARGET_NAME).asm : $(TARGET)
	objdump -d $< > $@

endif


%.o : %.c
	$(CC) -c  $< $(CFLAGS) -o $@ \
	$(PLATFORM_TARGET) 


.PHONY: build
build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) $(PLATFORM_TARGET) \
	 -o $@ 
	size $@ 


.PHONY: compile-all
compile-all: $(OBJS) 


.PHONY: clean
clean:
	rm -f *.o *.i *.asm *.d *.out *.map  




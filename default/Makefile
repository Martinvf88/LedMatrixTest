###############################################################################
# Makefile for the project LedMatrixTest
###############################################################################

## General Flags
PROJECT = LedMatrixTest
MCU = atmega328p
TARGET = LedMatrixTest.elf
CC = avr-gcc.exe

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=LedMatrixTest.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = LedMatrixTest.o Timer1.o MatrixColor.o MatrixGraphs.o Delay20.o UART0.o Timer2.o SetIntClk.o Clock.o EEPROM.o Configuration.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) LedMatrixTest.hex LedMatrixTest.eep LedMatrixTest.lss size

## Compile
UART0.o: ../UART0.S
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

LedMatrixTest.o: ../LedMatrixTest.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Timer1.o: ../Timer1.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

MatrixColor.o: ../MatrixColor.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

MatrixGraphs.o: ../MatrixGraphs.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Delay20.o: ../Delay20.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Timer2.o: ../Timer2.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SetIntClk.o: ../SetIntClk.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Clock.o: ../Clock.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

EEPROM.o: ../EEPROM.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Configuration.o: ../Configuration.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) LedMatrixTest.elf dep/* LedMatrixTest.hex LedMatrixTest.eep LedMatrixTest.lss LedMatrixTest.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)


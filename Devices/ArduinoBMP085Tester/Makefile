include ../../Makefile.common

# Sources

CPP_SRC += \
main.cpp

# Project name
PROJ_NAME=arduinobmp085tester
OUTPATH=build


vpath %.c src
vpath %.cpp src
vpath %.a ../../lib

# Includes
CFLAGS += -Iinc
CFLAGS += -I../../lib/arduino/inc
CFLAGS += -I../../lib/arduino/conf
CFLAGS += -I../../lib/arduinowire
CFLAGS += -I../../lib/adafruitbmp085

CXXFLAGS += -Iinc
CXXFLAGS += -I../../lib/arduino/inc
CXXFLAGS += -I../../lib/arduino/conf
CXXFLAGS += -I../../lib/arduinowire
CXXFLAGS += -I../../lib/adafruitbmp085

# Library paths
LIBPATHS  = -L../../lib/arduino -L../../lib/arduinowire -L../../lib/adafruitbmp085


# COMMENT:
# -lc -lm <..> -lc must be added to prevent
# errors like this: "relocation truncated to fit: R_AVR_13_PCREL against symbol"
#
# references:
# http://forum.arduino.cc/index.php/topic,40215.0.html
# http://stackoverflow.com/questions/8188849/avr-linker-error-relocation-truncated-to-fit
 

# Libraries to link
LIBS  = -lm -ladafruitbmp085 -larduinowire -larduino -lc

OBJS = $(CPP_SRC:.cpp=.o)

###################################################

.PHONY: lib proj

flash: all 
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH)

all: lib proj 
	$(SIZE) $(OUTPATH)/$(PROJ_NAME).elf

lib:
	$(MAKE) -C ../../lib 

proj: prepare $(OUTPATH)/$(PROJ_NAME).elf
	

$(OUTPATH)/$(PROJ_NAME).elf: $(CPP_SRC)
	mkdir -p $(OUTPATH)	
	#bash ./scripts/setbuildid.script
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBPATHS) $(LIBS)
	$(OBJCOPY) -j .text  -j .data -O ihex $(OUTPATH)/$(PROJ_NAME).elf $(OUTPATH)/$(PROJ_NAME).hex
	
cleanall: clean
	$(MAKE) clean -C ../../lib # Remove this line if you don't want to clean the libs as well

prepare:
	rm -f $(OUTPATH)/$(PROJ_NAME).elf
	rm -f $(OUTPATH)/$(PROJ_NAME).hex
	rm -f $(OUTPATH)/$(PROJ_NAME).bin
	
clean:
	rm -f *.o
	rm -f $(OUTPATH)/$(PROJ_NAME).elf
	rm -f $(OUTPATH)/$(PROJ_NAME).hex
	rm -f $(OUTPATH)/$(PROJ_NAME).bin

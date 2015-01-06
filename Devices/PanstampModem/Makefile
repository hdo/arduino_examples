include ../../Makefile.common

# Sources

CPP_SRC += \
modem.cpp \
main.cpp

# Project name
PROJ_NAME=panstampmodem
OUTPATH=build


vpath %.c src
vpath %.cpp src
vpath %.a ../../lib

# Includes
CFLAGS += -Iinc
CFLAGS += -I../../lib/arduino/inc
CFLAGS += -I../../lib/arduino/conf
CFLAGS += -I../../lib/arduinoeeprom/inc
CFLAGS += -I../../lib/timerone/inc
CFLAGS += -I../../lib/panstamp/inc

CXXFLAGS += -Iinc
CXXFLAGS += -I../../lib/arduino/inc
CXXFLAGS += -I../../lib/arduino/conf
CXXFLAGS += -I../../lib/arduinoeeprom/inc
CXXFLAGS += -I../../lib/timerone/inc
CXXFLAGS += -I../../lib/panstamp/inc

# Library paths
LIBPATHS = -L../../lib/arduino -L../../lib/eeprom -L../../lib/timerone -L../../lib/panstamp

# Libraries to link
#LIBS  = -larduino -larduinoeeprom -ltimerone -lpanstamp
LIBS  = -larduino -leeprom -ltimerone -lpanstamp

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

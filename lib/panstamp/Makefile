include ../../Makefile.common

# Includes
CFLAGS += -Iinc 
CFLAGS += -I../arduino/inc
CFLAGS += -I../arduino/conf # for pins_arduino.h
CFLAGS += -I../eeprom/inc

CXXFLAGS += -Iinc
CXXFLAGS += -I../arduino/inc
CXXFLAGS += -I../arduino/conf # for pins_arduino.h
CXXFLAGS += -I../eeprom/inc

# Sources
C_SRC = 

CPP_SRC = src/cc1101.cpp \
src/panstamp.cpp \
src/register.cpp \
src/spi.cpp \
src/swcommand.cpp \
src/swpacket.cpp \
src/swquery.cpp \
src/swstatus.cpp  

OBJS := $(C_SRC:.c=.o) $(CPP_SRC:.cpp=.o)
LIBNAME = libpanstamp.a

# Library paths
LIBPATHS = -L../arduino -L../eeprom 

# Libraries to link
LIBS  = -larduino -leeprom 


all: $(LIBNAME)
	$(SIZE) $(LIBNAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^ $(LIBPATHS) $(LIBS)
	
$(LIBNAME): $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) $(LIBNAME)
	
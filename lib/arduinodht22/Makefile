include ../../Makefile.common

# Includes
CFLAGS += -I. 
CFLAGS += -I../arduino/inc
CFLAGS += -I../arduino/conf # for pins_arduino.h

CXXFLAGS += -Iinc
CXXFLAGS += -I../arduino/inc
CXXFLAGS += -I../arduino/conf # for pins_arduino.h

# Sources
C_SRC = 

CPP_SRC = DHT22.cpp

OBJS := $(C_SRC:.c=.o) $(CPP_SRC:.cpp=.o)
LIBNAME = libarduinodht22.a

all: $(LIBNAME)
	$(SIZE) $(LIBNAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

$(LIBNAME): $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) $(LIBNAME)
	
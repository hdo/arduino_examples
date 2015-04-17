include ../../Makefile.common

# Includes
CFLAGS += -I. 
CFLAGS += -Iutility 
CFLAGS += -I../arduino/inc
CFLAGS += -I../arduino/conf # for pins_arduino.h

CXXFLAGS += -I.
CXXFLAGS += -Iutility
CXXFLAGS += -I../arduino/inc
CXXFLAGS += -I../arduino/conf # for pins_arduino.h

# Sources
C_SRC = utility/twi.c

CPP_SRC = Wire.cpp 

OBJS := $(C_SRC:.c=.o) $(CPP_SRC:.cpp=.o)
LIBNAME = libarduinowire.a

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
	
include ../../Makefile.common

# Includes
CFLAGS += -Isrc 
CFLAGS += -I../arduino/inc
CFLAGS += -I../arduino/conf

CXXFLAGS += -Isrc
CXXFLAGS += -I../arduino/inc
CXXFLAGS += -I../arduino/conf


# Sources
C_SRC = 

CPP_SRC = src/OneWire.cpp

OBJS := $(C_SRC:.c=.o) $(CPP_SRC:.cpp=.o)
LIBNAME = libonewire.a

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
	
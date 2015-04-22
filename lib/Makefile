include ../Makefile.common

# Build all libraries

all:
	$(MAKE) -C arduino
	$(MAKE) -C arduinowire
	$(MAKE) -C eeprom
	$(MAKE) -C timerone
	$(MAKE) -C panstamp
	$(MAKE) -C adafruitdht
	$(MAKE) -C adafruitbmp085
	$(MAKE) -C arduinodht22
	$(MAKE) -C onewire
	$(MAKE) -C dallastemperature

clean:
	$(MAKE) clean -C arduino
	$(MAKE) clean -C arduinowire
	$(MAKE) clean -C eeprom
	$(MAKE) clean -C timerone
	$(MAKE) clean -C panstamp
	$(MAKE) clean -C adafruitdht
	$(MAKE) clean -C adafruitbmp085
	$(MAKE) clean -C arduinodht22
	$(MAKE) clean -C onewire
	$(MAKE) clean -C dallastemperature
	
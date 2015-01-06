include ../Makefile.common

# Build all libraries

all:
	$(MAKE) -C arduino
	$(MAKE) -C eeprom
	$(MAKE) -C timerone
	$(MAKE) -C panstamp

clean:
	$(MAKE) clean -C arduino
	$(MAKE) clean -C eeprom
	$(MAKE) clean -C timerone
	$(MAKE) clean -C panstamp
	
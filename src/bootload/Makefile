PREFIX  = $(HOME)/TomboWorks/project/step12/local
ARCH    = h8300-elf
BINDIR  = $(PREFIX)/bin
ADDNAME = $(ARCH)-

AR      = $(BINDIR)/$(ADDNAME)ar
AS      = $(BINDIR)/$(ADDNAME)as
CC      = $(BINDIR)/$(ADDNAME)gcc
LD      = $(BINDIR)/$(ADDNAME)ld
NM      = $(BINDIR)/$(ADDNAME)nm
OBJCOPY = $(BINDIR)/$(ADDNAME)objcopy
OBJDUMP = $(BINDIR)/$(ADDNAME)objdump
RANLIB  = $(BINDIR)/$(ADDNAME)ranlib
STRIP   = $(BINDIR)/$(ADDNAME)strip

H8WRITE        = $(BINDIR)/h8write
H8WRITE_SERDEV = /dev/ttyUSB0

OBJS    = vector.o startup.o main.o
OBJS   += lib.o serial.o xmodem.o elf.o

TARGET  = kzload

CFLAGS  = -Wall -mh -nostdinc -nostdlib -fno-builtin
CFLAGS += -I.
CFLAGS += -Os
CFLAGS += -DKZLOAD

LFLAGS  = -static -T ld.scr -L.

.SUFFIXES: .c .o
.SUFFIXES: .s .o

.PHONY: all
all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)
	cp $(TARGET) $(TARGET).elf
	$(STRIP) $(TARGET)

.c.o : $<
	$(CC) -c $(CFLAGS) $<

.s.o : $<
	$(CC) -c $(CFLAGS) $<

$(TARGET).mot : $(TARGET)
	$(OBJCOPY) -O srec $(TARGET) $(TARGET).mot

.PHONY: image
image : $(TARGET).mot

.PHONY: write
write : $(TARGET).mot
	$(H8WRITE) -3069 -f20 $(TARGET).mot $(H8WRITE_SERDEV)

.PHONY: clean
clean :
	rm -f $(OBJS) $(TARGET) $(TARGET).elf $(TARGET).mot

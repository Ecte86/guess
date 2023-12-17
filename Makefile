CC = oscar64
BINDIR = bin
EXE = guess
CFLAGS = -v
SRCS = $(shell find . -name '*.c')
INC = $(shell find . -name '*.h')

EMU = x64sc -silent

.PHONY: all clean

all:
	$(CC) -v $(SRCS) $(INC) -o=$(BINDIR)/$(EXE).prg

run:
	$(EMU) $(BINDIR)/$(EXE).prg

clean:
	rm $(BINDIR)/$(EXE).prg

X=5
CFLAGS=-Wall -Wextra -O2 -ansi -DX=$X

all: main
main: main.o
main.o: main.c

.PHONY: clean
clean:
	$(RM) main main.o

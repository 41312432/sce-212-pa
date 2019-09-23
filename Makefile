TARGET	= pa1
CFLAGS	= -g

all: pa1

pa1: pa1.c
	gcc $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf pa1 *.o pa1.dSYM

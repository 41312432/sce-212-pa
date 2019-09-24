TARGET	= pa1
CFLAGS	= -g

all: pa1

pa1: pa1.c
	gcc $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf pa1 *.o pa1.dSYM

.PHONY: test-r
test-r: pa1 testcase-r-format
	./$< testcase-r-format

.PHONY: pa1 test-shifts
test-shifts: pa1 testcase-shifts
	./$< testcase-shifts

.PHONY: pa1 test-i
test-i: pa1 testcase-i-format
	./$< testcase-i-format

.PHONY: test-all
test-all: test-r test-shifts test-i

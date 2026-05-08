# Makefile for the Juliet C/C++ test cases.
#
# CodeQL needs to observe the compiler running so it can extract source
# into its internal database. Anything that compiles will work - we don't
# need the binaries to actually run, we just need cc to be invoked on
# every .c file.

CC ?= gcc

# -fno-stack-protector and -O0 keep the test cases honest - we don't want
# the compiler optimising away the deliberately-unsafe patterns.
CFLAGS = -O0 -fno-stack-protector -Wall -Wno-unused-result -Wno-format-security

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

.PHONY: all clean

all: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

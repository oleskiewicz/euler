CC      = cc
CFLAGS  = -std=c99 -Wall -O2 -march=native
LDFLAGS = -lm

%: %.c lib.h
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $<

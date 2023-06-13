CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror
OBJS = mult.o generate.o print.o

all: multtest matbench
	rm *.o

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

multtest: multtest.c $(OBJS)

matbench: matbench.c $(OBJS)

clean:
	rm -f *.o multtest matbench


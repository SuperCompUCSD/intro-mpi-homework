EXE = main
OBJS = main.o
CC = gcc
DEBUG = -g
WARN = -Wall -Wextra
CFLAGS = -std=gnu11 -O2 $(DEBUG) $(WARN)
LIBS = -lm
.PHONY: clean run

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

run:
	make
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJS)

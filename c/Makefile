EXE = main
OBJS = main.o
CC = mpicc
DEBUG = -g
WARN = -Wall -Wextra
CFLAGS = -std=gnu11 -O3 $(DEBUG) $(WARN)
LIBS = -lm
EXECDIR = /tmp/$(USER)
.PHONY: clean run single_node multi_node

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

$(EXECDIR):
	mkdir $(EXECDIR)
	ssh b 'mkdir $(EXECDIR)'
	ssh c 'mkdir $(EXECDIR)'

$(EXECDIR)/$(EXE): $(EXECDIR) $(EXE)
	cp $(EXE) $(EXECDIR)
	scp $(EXE) 'b:$(EXECDIR)/'
	scp $(EXE) 'c:$(EXECDIR)/'

run: $(EXE) $(EXECDIR)
	$(EXECDIR)/$(EXE)

single_node: $(EXECDIR)/$(EXE)
	mpirun $(EXECDIR)/$(EXE)

multi_node: $(EXECDIR)/$(EXE)
	mpirun -hostfile hos $(EXECDIR)/$(EXE)

clean:
	rm -rf $(EXE) $(OBJS) $(EXECDIR)
	ssh b 'rm -rf $(EXECDIR)'
	ssh c 'rm -rf $(EXECDIR)'

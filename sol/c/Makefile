EXE = main
OBJS = main.o
CC = mpicc
DEBUG = -g
WARN = -Wall -Wextra
CFLAGS = -std=gnu11 -O3 $(DEBUG) $(WARN) -O3
LIBS = -lm
EXECDIR = /tmp/$(USER)
.PHONY: clean run single_node multi_node dist runscript

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

$(EXECDIR):
	mkdir $(EXECDIR)
	ssh b 'mkdir $(EXECDIR)'
	ssh c 'mkdir $(EXECDIR)'
hosts:
	echo 'localhost\n10.0.1.14\n10.0.1.16' | tee hosts

$(EXECDIR)/$(EXE): $(EXECDIR) $(EXE)
	cp $(EXE) $(EXECDIR)
	scp $(EXE) 'b:$(EXECDIR)/'
	scp $(EXE) 'c:$(EXECDIR)/'
dist: $(EXECDIR)/$(EXE) hosts runscript

runscript: hosts $(EXECDIR) $(EXE)
	echo '#!/usr/bin/bash\nmpirun -hostfile hosts $(EXECDIR)/$(EXE) $$@' | tee run
	chmod +x run

run: $(EXE)
	./$(EXE)

single_node: dist
	mpirun $(EXECDIR)/$(EXE)

multi_node: dist
	mpirun -hostfile hosts $(EXECDIR)/$(EXE)

clean:
	rm -rf $(EXE) $(OBJS) $(EXECDIR) hosts run
	ssh b 'rm -rf $(EXECDIR)'
	ssh c 'rm -rf $(EXECDIR)'

OBJS= main.o dummy_functions.o 
SRCS= main.c dummy_functions.c
compiler=gcc
test_input=-1
#OBS:se poate din linia de comanda sa schimbi variabile
#ex:make test_input=2 va afisa 2,nu -1
#ex:make test_input=4 all
#ex:make all test_input=10
all: obj_files
	@echo $(test_input)
	@echo $(compiler)
	@echo Finished building project
obj_files: $(OBJS)
	$(compiler) $(OBJS) -o output
	$(compiler) -S $(SRCS)
clean:
#need to fix this rule
	@rm *.o *.s *.exe 
	@echo 'Finished cleaning'
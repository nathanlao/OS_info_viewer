CFLAGS := -Werror -Wfatal-errors -g

all: my_version.o my_current_processes.o my_memory_util.o

my_version.o: 
	gcc $(CFLAGS) -o my_version my_version.c

my_current_processes.o:
	gcc $(CFLAGS) -o my_current_processes my_current_processes.c

my_memory_util.o:
	gcc $(CFLAGS) -o my_memory_util my_memory_util.c

clean:
	rm -f my_version my_current_processes my_memory_util *.o
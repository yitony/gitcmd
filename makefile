CC=gcc

gitcmd:main.o 
	$(CC) main.o func.o -o gitcmd
main.o:main.c func.o
	$(CC) -c   main.c
func.o:func.c 
	$(CC) -c  func.c

clean:
	rm -rf *.o gitcmd


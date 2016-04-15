CC=gcc
CF=-std=c11
DEPS=main.o brain.o bmp.o

net.exe: $(DEPS)
	$(CC) $(CF) $(DEPS) -o net.exe
	rm -Rf *.o

main.o:
	$(CC) $(CF) -c main.c -o main.o

brain.o:
	$(CC) $(CF) -c brain.c -o brain.o

bmp.o:
	$(CC) $(CF) -c bmp.c -o bmp.o

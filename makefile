all: main hdbn

hdbn: hdbn.o
	gcc -o hdbn hdbn.o

main: main.o
	gcc -o main main.o

hdbn.o: hdbn.c
	gcc -o hdbn.o -c hdbn.c

main.o: main.c
	gcc -o main.o -c main.c

clean:
	rm -f *.o

mrpropre: clean
	rm -f main
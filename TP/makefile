all: TP1 hdbn generateur

generateur: generateur.o
	gcc -o generateur generateur.o

hdbn: hdbn.o
	gcc -o hdbn hdbn.o

TP1: TP1.o
	gcc -o TP1 TP1.o

generateur.o: generateur.c
	gcc -o generateur.o -c generateur.c

hdbn.o: hdbn.c
	gcc -o hdbn.o -c hdbn.c

TP1.o: TP1.c
	gcc -o TP1.o -c TP1.c

clean:
	rm -f *.o

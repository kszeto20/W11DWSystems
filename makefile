all: main.o randP.o
	gcc -o output main.o randP.o

main.o: main.c randP.h
	gcc -c main.c

randP.o: randP.c
	gcc -c randP.c

clean:
	rm *.o
	rm output
	rm f1.txt

run:
	./output

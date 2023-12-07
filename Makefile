CC = gcc
LIBS = -lm

all: exe1 exe2 exe3

exe1: proyecto1.c
	$(CC) -o exe1 proyecto1.c

exe2: proyecto2.c
	$(CC) -o exe2 proyecto2.c $(LIBS)

exe3: proyecto3.c
	$(CC) -o exe3 proyecto3.c

run: 

p1: exe1
	./exe1

p2: exe2
	./exe2

p3: exe3
	./exe3

clean:
	rm exe1 exe2 exe3


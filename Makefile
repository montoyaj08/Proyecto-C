p1: proyecto1.c
    gcc -o exe1 proyecto1.c

p2: proyecto2.c
    gcc -o exe2 proyecto2.c

p3: proyecto3.c
    gcc -o exe3 proyecto3.c

.PHONY: all p1 p2 p3 run_p1 run_p2 run_p3

all: p1 p2 p3

run_p1: p1
    ./exe1

run_p2: p2
    ./exe2

run_p3: p3
    ./exe3


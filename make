qsort: qsort.o quicksort.o
	gcc -o qsort qsort.o quicksort.o

qsort.o: quicksort.h
	gcc -c qsort.c

quicksort.o: quicksort.c quicksort.h
	gcc -c quicksort.c

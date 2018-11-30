sort: sorting.o quicksort.o
	gcc -o sorting sorting.o quicksort.o

sorting.o: quicksort.h
	gcc -c sorting1471564.c

quicksort.o: quicksort.c quicksort.h
	gcc -c quicksort.c

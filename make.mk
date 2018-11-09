quicksort:quicksort.o qsort.o
    gcc -o quicksort quicksort.o qsort.o

qsort.o:quicksort.h
    gcc -c qsort.c

quicksort.o: quicksort.c quicksort.h
    gcc -c quicksort.c
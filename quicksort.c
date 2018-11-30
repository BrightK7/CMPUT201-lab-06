#include <stdio.h>
#include "quicksort.h"

void quicksort(int a[], int low, int high,int* compare_num)
{
  int middle;

  if (low >= high) return;
  middle = split(a, low, high,compare_num);
  quicksort(a, low, middle - 1,compare_num);
  quicksort(a, middle + 1, high,compare_num);
}

int split(int a[], int low, int high,int* compare_num)
{
  int part_element = a[low];

  for (;;) {
    while (low < high && part_element <= a[high]){
      high--;
      *compare_num++
    }
    if (low >= high) break;
    a[low++] = a[high];

    while (low < high && a[low] <= part_element){
      *compare_num++
      high--
    }
    if (low >= high) break;
    a[high--] = a[low];
  }

  a[high] = part_element;
  return high;
}
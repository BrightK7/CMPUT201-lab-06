/* mergesort() recursive definiton
 *
 * demo: several solutions from Midterm exam
 */

#include <stdio.h>
void mergesort1(int a[], int left, int right) {
	if (left >= right)
		return;
	
	int mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);

	// insert below C statements to merge two sorted subarrays:
	// v1: using a help array b[]
	int i = left, j = mid + 1, k = 0;
	int length = right - left + 1;
	int b[length];
	
	for (; k < length; k++) {
		if (a[i] <= a[j]) {
			b[k] = a[i++];
			if (i > mid) break;
		}
		else {
			b[k] = a[j++];
			if (j > right) break;
		}
	}
	for (; j <= right; j++)
		b[++k] = a[j];
	for (; i <= mid; i++)
		b[++k] = a[i];
	for (k = 0; k < length; k++) // need to copy back to a[]
		a[left + k] = b[k];
	return; // do not return b
}

void mergesort2(int a[], int left, int right) {
	if (left >= right)
		return;
	
	int mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);

	// insert below C statements to merge two sorted subarrays:
	// v2: not working since the right subarray is messed up
	//     counterexample: 3; 1, 2
	for (int i = left; i <= mid; i++)
		for (int j = mid + 1; j <= right; j++)
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	return;
}

void mergesort(int a[], int left, int right) {
	if (left >= right)
		return;
	
	int mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);

	// insert below C statements to merge two sorted subarrays:
	// v3: merging inside a[], but needs a lot of data moving
	for (int i = left; i <= mid; i++)
		for (int j = mid + 1; j <= right; j++)
			if (a[i] > a[j]) { // moving
				int temp = a[j];
				for (int k = j; k > i; k--)
					a[k] = a[k-1];
				a[i] = temp;
				mid++; // keep the end of left subarray unchanged
			}
	return;
}
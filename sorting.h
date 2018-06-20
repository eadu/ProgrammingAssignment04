#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Quick_Sort(long *Array, int Size);
int partitionArray(long *Array, int lb, int ub);
long medianOfThree(long *Array, int lb, int ub);
void quickSort(long *Array, int lb, int ub);
void swapElements(long *Array, int element1, int element2);

void Merge_Sort(long *Array, int Size);
void mergeSort(long *Array, long *temp, int lb, int ub);
void merge(long *Array, long *temp, int lb, int mid, int ub);
void insertionSort(long *Array, int lb, int ub);



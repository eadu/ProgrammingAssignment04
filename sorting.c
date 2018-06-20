#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sorting.h"

void Quick_Sort(long *Array, int Size)
{	
	quickSort(Array, 0, Size - 1);
}
void quickSort(long *Array, int lb, int ub)
{
	while(ub - lb > 25)
	{
		int partitionIndex;
		
		partitionIndex = partitionArray(Array, lb, ub);
		
		if(partitionIndex - lb + 1 < ub - partitionIndex)
		{
			quickSort(Array, lb, partitionIndex);
			lb = partitionIndex + 1;
		}
		else
		{
			quickSort(Array, partitionIndex + 1, ub);
			ub = partitionIndex;
		}
	}
	insertionSort(Array, lb, ub);
}

int partitionArray(long *Array, int lb, int ub)
{
	long pivot;
	int left;
	int right;

	pivot = medianOfThree(Array, lb, ub);
	left = lb - 1;
	right = ub + 1;
	while(true)
	{
		do
		{
			right--;
		}while(Array[right] > pivot);
		
		do
		{
			left++;
		}while(Array[left] < pivot);
		
		if(left < right)
		{
			swapElements(Array, left, right);
		}
		else
		{
			return right;
		}
	}
}

long medianOfThree(long *Array, int lb, int ub)
{
	int mid;
	long median;
	
	mid = (ub + lb) / 2;
	
	if(Array[mid] < Array[lb])
	{
		swapElements(Array, mid, lb);
	}
	if(Array[ub] < Array[lb])
	{
		swapElements(Array, lb, ub);
	}
	if(Array[ub] < Array[mid])
	{
		swapElements(Array, ub, mid);
	}
	
	swapElements(Array, mid, ub - 1);
	median = Array[ub - 1];
	
	return median;
}

void swapElements(long *Array, int element1, int element2)
{
	long temp;
	temp = Array[element1];
	Array[element1] = Array[element2];
	Array[element2] = temp;
}

void insertionSort(long *Array, int lb, int ub)
{
	int lcv1;
	int lcv2;
	long temp;

	for(lcv1 = ub; lcv1 > lb; lcv1--)
	{
		if(Array[lcv1] < Array[lcv1 - 1])
		{
			swapElements(Array, lcv1, lcv1 -1);
		}
	}
	for(lcv1 = lb + 2; lcv1 <= ub; lcv1++)
	{
		temp = Array[lcv1];
		lcv2 = lcv1;
		while(Array[lcv2 -1] > temp)
		{
			Array[lcv2] = Array[lcv2 - 1];
			lcv2--;
		}
		Array[lcv2] = temp;
	}
}

void Merge_Sort(long *Array, int Size)
{
	long *temp;
	
	temp = (long *)malloc(Size * sizeof(long));
	if(temp == NULL)
	{
		fprintf(stderr, "Could not allocate memory for temp array");
		return;
	}
	mergeSort(Array, temp, 0, Size - 1);
	free(temp);
}

void mergeSort(long *Array, long *temp, int lb, int ub) 
{	
	int mid;
	
	mid = (ub + lb) / 2;
	
	if(mid - lb < 25)
	{
		insertionSort(Array, lb, mid);
	}
	else
	{
		mergeSort(Array, temp, lb, mid);
	}
	if(ub - mid <= 25)
	{
		insertionSort(Array, mid + 1, ub);
	}
	else
	{
		mergeSort(Array, temp, mid + 1, ub);
	}
	merge(Array, temp, lb, mid, ub);
}

void merge(long *Array, long *temp, int lb, int mid, int ub)
{	
	int left;
	int right;
	int current;
	
	//Copy the first half of the array into temp
	for(left = lb; left <= mid; left++)
	{
		temp[left] = Array[left];
	}
	//Copies the second half of the array into temp but in reverse order
	for(right = ub; right > mid; right--)
	{
		temp[left++] = Array[right];
	}
	//Merge the two subarrays
	left = lb;
	right =  ub;
	for(current = lb; current <= ub; current++)
	{
		if(temp[left] <= temp[right])
		{
			Array[current] = temp[left++];
		}
		else
		{
			Array[current] = temp[right--];
		}
	}
}

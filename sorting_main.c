#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sorting.h"


long *Load_Into_Array(char *Filename, int *Size);
void printArray(long *Array, int Size);
void checkSorted(long *Array, int Size);

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		fprintf(stderr, "Usage: ./proj4 -q or -m inputfile outputfile");
		return EXIT_FAILURE;
	}
	
	long *Array;
	int Size;
	double sortTime;
	clock_t start;
	clock_t end;
	Array = Load_Into_Array(argv[2], &Size);
	if(strcmp(argv[1], "-q") == 0)
	{
		start = clock();
		Quick_Sort(Array, Size);
		end = clock();
		sortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("time = %f\n", sortTime);
	}
	else if(strcmp(argv[1], "-m") == 0)
	{
		start = clock();
		Merge_Sort(Array, Size);
		end = clock();
		sortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("time = %f\n", sortTime);
	}
	else
	{
		fprintf(stderr, "Usage: ./proj4 -q or -m inputfile outputfile");
		return EXIT_FAILURE;
	}
	checkSorted(Array, Size - 1);
	free(Array);
	return EXIT_SUCCESS;
}

//For testing Purposes
void printArray(long *Array, int Size)
{
	int i;
	for(i = 0; i < Size; i++)
	{
		printf("%ld ", Array[i]); 
	}
	printf("\n");
}

long *Load_Into_Array(char *Filename, int *Size)
{
	FILE *inptr;
	inptr = fopen(Filename, "rb");
	if (inptr == NULL)
	{
		fprintf(stderr, "Error: Could not open binary file.");
		return NULL;
	}
	long numBytes;
	fseek(inptr, 0L, SEEK_END);
	numBytes = ftell(inptr);
	(*Size) = numBytes / sizeof(long);
	long *array;
	array = (long *)malloc((*Size) * sizeof(long));
	if (array == NULL)
	{
		fprintf(stderr, "Error: Could not allocate memory for array");
		fclose(inptr);
		return NULL;
	}
	fseek(inptr, 0L, SEEK_SET);
	fread(array, sizeof(long), (*Size), inptr);
	fclose(inptr);
	return array;
}

void checkSorted(long *Array, int Size)
{
	int lcv;
	
	for(lcv = 0; lcv < Size; lcv++)
	{
		if(Array[lcv] > Array[lcv + 1])
		{
			fprintf(stderr, "The array is not sorted\n");
			break;
		}
	}
}


#include <stdio.h>
#include <stdlib.h>
#include "shell_array.h"

long *Array_Load_From_File(char *filename, int *size)
{
	long * data = malloc(sizeof(long) * (*size));
	
	FILE *fp;
	fp = fopen(filename, "rb");
	fread(data, sizeof(long), *size, fp);
	fclose(fp);
	// printf("Size of data array: %d\n", *size);
	// for(int i = 0; i<(*size); i++)
	// {
	// 	printf("#%d:   %ld\n", i, data[i]);
	// }

	return data;
}

int Array_Save_To_File(char *filename, long *array, int size)
{
	FILE *fp;
	fp = fopen(filename, "wb");
	int s = fwrite(array, sizeof(long), size, fp);
	fclose(fp);
	return s;
}

void Array_Shellsort(long *array, int size, long *n_comp)
{
	
}
#include <stdio.h>
#include <stdlib.h>
#include "shell_array.h"
#include "sequence.h"

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
	int seq_size = 0;
	*n_comp = 0;
	long *sequence = Generate_2p3q_Seq(size, &seq_size);
	int gap;
	long temp;
	
	for(int s = 0; s<seq_size; s++)
	{
		*n_comp += 1;
		gap = sequence[s];
		int i,j;
		for(i = gap; i<size; i++)
		{
			*n_comp += 1;
			temp = array[i];
			for(j = i; ((j>=gap) && array[j-gap]>temp); j-=gap)
			{
				*n_comp += 1;
				array[j] = array[j-gap];
			}
			*n_comp += 1;
			array[j] = temp;
		}
		*n_comp += 1;
	}
	*n_comp += 1;
	free(sequence);
}
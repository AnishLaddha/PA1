#include <stdio.h>
#include <stdlib.h>
#include "shell_array.h"
#include "sequence.h"

long *Array_Load_From_File(char *filename, int *size)
{
	int data_size = 0;
	FILE *f;
	f = fopen(filename, "rb");
	fseek(f,0L, SEEK_END);
	data_size = ftell(f)/8;
	fseek(f, 0L, SEEK_SET);
	fclose(f);
	*size = data_size;
	long * data = malloc(sizeof(long) * (*size));
	FILE *fp;
	fp = fopen(filename, "rb");
	if(fread(data, sizeof(long), *size, fp) != *size)
	{
		printf("ERROR IN READ\n");
	}
	fclose(fp);


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
		gap = sequence[s];
		int i,j;
		for(i = gap; i<size; i++)
		{
			temp = array[i];
			for(j = i; ((j>=gap) && array[j-gap]>temp); j-=gap)
			{
				*n_comp += 1;
				array[j] = array[j-gap];
			}
			*n_comp += 1;
			array[j] = temp;
		}
	}
	free(sequence);
}
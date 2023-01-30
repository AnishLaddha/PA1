#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

int main()

{
  int data_size = 15;
	long* data = Array_Load_From_File("examples/15.b", &data_size);
  
	int test_size;
	long* sequence = Generate_2p3q_Seq(data_size,&test_size);

	for(int i = 0; i<test_size; i++)
	{
		printf("%ld ", sequence[i]);
	}
	printf("\n");

	long comps;
	Array_Shellsort(data, data_size, &comps);
	
	for(int i = 0; i<data_size; i++)
	{
		printf("%d: %ld \n", i,data[i]);
	}
	printf("\n");
	
	int b = Array_Save_To_File("testout.b", data, data_size);
	
	free(data);
	free(sequence);
	return 0;
}
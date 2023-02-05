#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

//static int check_arr(long* array, int n);

int main()

{
  int data_size;

	FILE *f;
	f = fopen("examples/15.b", "rb");
	fseek(f,0L, SEEK_END);
	data_size = ftell(f)/8;
	fseek(f, 0L, SEEK_SET);
	fclose(f);
	// printf("FILE SIZE: %d\n", data_size);
	
	int i;
	long* data = Array_Load_From_File("examples/15.b", &data_size);
	printf("Original Array: \n");
  for(i = 0; i<data_size; i++)
	{
		printf("%d: %ld \n", i,data[i]);
	}
	printf("\n");
	int test_size;
	long* sequence = Generate_2p3q_Seq(data_size,&test_size);

	// for(int i = 0; i<test_size; i++)
	// {
	// 	printf("%ld ", sequence[i]);
	// }
	// printf("\n");

	long comps;
	Array_Shellsort(data, data_size, &comps);

	// printf("Sorted Array: \n");
	// for(i = 0; i<data_size; i++)
	// {
	// 	printf("%d: %ld \n", i,data[i]);
	// }
	// printf("\n");
	
	// if(check_arr(data, data_size)==1)
	// {
	// 	printf("sorted\n");
	// } else {
	// 	printf("not sorted \n");
	// }

	int b = Array_Save_To_File("testout.b", data, data_size);
	
	free(data);
	free(sequence);
	return 0;
}

// static int check_arr(long* array, int n)
// {
// 	for(int i = 1; i<n; i++)
// 	{
// 		if(array[i]<array[i-1])
// 		{
// 			return 0;
// 		}
// 	}
// 	return 1;
// }
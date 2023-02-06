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
	
	//int i;
	long* data = Array_Load_From_File("examples/15.b", &data_size);
	//int test_size;
	//long* sequence = Generate_2p3q_Seq(data_size,&test_size);
	long comps;
	Array_Shellsort(data, data_size, &comps);
	int b = Array_Save_To_File("testout.b", data, data_size);
	printf("%ld\n", comps);
	free(data);
	//free(sequence);
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
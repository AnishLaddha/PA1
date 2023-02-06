#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"


int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("Incorrect # of arguements.\n");
		return 1;
	}
	char flag = argv[1][1];
	char *input = argv[2];
	char *output = argv[3];
	// printf("flag:%c\n", flag);
	// printf("%s\n", input);
	// printf("%s\n", output);
	if(flag == 'a')
	{
		int data_size=0;
		// FILE *f;
		// f = fopen(input, "rb");
		// fseek(f,0L, SEEK_END);
		// data_size = ftell(f)/8;
		// fseek(f, 0L, SEEK_SET);
		// fclose(f);

		long* data = Array_Load_From_File(input, &data_size);
		long comps;
		Array_Shellsort(data, data_size, &comps);
		int b;
		b = Array_Save_To_File(output, data, data_size);
		if(b<0)
		{
			printf("0\n");
		}
		
		printf("%ld\n", comps);
		free(data);
	}
	else if (flag == 'l')
	{
		// int data_size;
		// FILE *f;
		// f = fopen(input, "rb");
		// fseek(f,0L, SEEK_END);
		// data_size = ftell(f)/8;
		// fseek(f, 0L, SEEK_SET);
		// fclose(f);

		//printf("flagl:%c\n", flag);
		Node * data = List_Load_From_File(input);
		long comps=0;
		data = List_Shellsort(data, &comps);
		printf("%ld\n",comps);
		int b;
		b = List_Save_To_File(output, data);
		if(b<0)
		{
			printf("ERROR\n");
		}

		Node* top;
  	while(data != NULL)
		{
			top = data;
			data = data->next;
			free(top);
		}
		
		return 0;
	}
	else {
		printf("Unrecognized Flag. Please select 'a' for array or 'l' for linked list.\n");
		return 1;
	}
	return 0;
}



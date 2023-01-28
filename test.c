#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

int main()

{
  int a = 1000;
	long* data = Array_Load_From_File("examples/1K.b", &a);
  int b = Array_Save_To_File("testout.b", data, a);
	free(data);
	return 0;
}
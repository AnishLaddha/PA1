#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

//static int check_arr(long* array, int n);
static void free_list(Node* head);

int main()
{
  Node* head = NULL;
  Node * data = List_Load_From_File("examples/1K.b");
  head = data;
  long a;
  data = List_Shellsort(data, &a);
  int b = List_Save_To_File("testout.b", data);
  free_list(data);
  
  return 0;
}


static void free_list(Node* data)
{
  Node* head;
  while(data != NULL)
  {
    head = data;
    data = data->next;
    free(head);
  }
}
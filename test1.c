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
  Node * data = List_Load_From_File("examples/1M.b");
  head = data;
  int count = 0;
  while(data != NULL)
  {
    //printf("%d: %ld \n",count, data->value);
    data = data->next; 
    count++;
  }
  data = head;
  long a=count;
  
  data = List_Shellsort(data, &a);
  head = data;  
  printf("\n\n\n");
  data = head;
  //printf("line 35 count: %d\n", count);
  int b = List_Save_To_File("testout.b", data);
  printf("Num int stored: %d\n",b);
  free_list(data);
  
  return 0;
}


static void free_list(Node* head)
{
  Node* data;
  while(head != NULL)
  {
    data = head;
    head = head->next;
    free(data);
  }
}
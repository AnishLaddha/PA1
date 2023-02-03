#include <stdio.h>
#include <stdlib.h>
#include "shell_array.h"
#include "sequence.h"

Node *List_Load_From_File(char *filename)
{
  Node *start_of_list = malloc(sizeof(Node));
  Node *curr;
  
  Node *prev;
  File * fp;
  long buffer;
  fp = fopen(filename, "rb");
  int start = 1;
  while(fread(&buffer, sizeof(long), 1, fp) != 0)
  {
    prev = prev->next;
    curr = curr->next;
    *curr = malloc(sizeof(Node));
    curr->value = buffer;
    curr->next = NULL;
    if(start ==1)
    {
      start_of_list->next = curr;
      prev = start_of_list;
      start = 0;
    }

  }
  return start_of_list;
  fclose(fp);
}

int List_Save_To_File(char *filename, Node *list)
{
	FILE *fp;
	fp = fopen(filename, "wb");
	int s = 0;
	while(list !=NULL && fwrite(list->value, sizeof(long), 1, fp) != 0)
	{
		s+=1;
		list = list->next;
	}
	return s;
  return 0;

}

//Node *List_Shellsort(Node *list, long *n_comp){}

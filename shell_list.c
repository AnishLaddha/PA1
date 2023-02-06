#include <stdio.h>
#include <stdlib.h>
#include "shell_list.h"
#include "sequence.h"

static Node *sort_pass(Node *head, long gap, long *n_comp);

Node *List_Load_From_File(char *filename)
{
  //Node *start_of_list = malloc(sizeof(Node));
  Node *curr = NULL;
  FILE * fp;
  long buffer;
  fp = fopen(filename, "rb");
  Node * prev = NULL;
  
  int count = 0;

  while(fread(&buffer, sizeof(long), 1, fp) != 0)
  {
    prev = (Node *)malloc(sizeof(Node));
    prev->value = buffer;
    prev->next = curr;
    curr = prev;
    count++;
  }
  fclose(fp);
  return curr;
}

int List_Save_To_File(char *filename, Node *list)
{
	FILE *fp;
	fp = fopen(filename, "wb");
	int s = 0;
	while(list !=NULL && fwrite(&(list->value), sizeof(long), 1, fp) != 0)
	{
		s++;
		list = list->next;
	}
  fclose(fp);
	return s;
}

Node *List_Shellsort(Node *list, long *n_comp)
{
  if(list == NULL)
  {
    return list;
  }
  int size=0;
  Node* head = NULL;
  head = list;
  while(head != NULL)
  {
    head = head->next; 
    size++;
  }
  *n_comp = 0;
  int seq_size = 0;
	long *sequence = Generate_2p3q_Seq(size, &seq_size);
  int gap;
  for(int i = 0; i<seq_size; i++)
  {
    gap = sequence[i];
    list = sort_pass(list, gap, n_comp);
    //Node* data = list;
  }
  free(sequence);

  return list;
}

static Node* sort_pass(Node *head, long gap, long *n_comp)
{
  int swap;
  do
  {
    int count = 0;
    swap = 0;
    Node *start;
    Node *curr1 = malloc(sizeof(Node));
    start = curr1;
    curr1->next = head;
    Node *curr2;
    curr2 = head;
    while(count<gap-1 && curr2->next!= NULL)
    {
      curr2 = curr2->next;
      count++;
    }

    while(curr2!=NULL && curr2->next!=NULL)
    {
      *n_comp += 1;
      if(curr2->next->value < curr1->next->value)
      {

        if(gap != 1)
        {
          Node *tmp1 = curr1->next->next;
          Node *tmp2 = curr2->next->next;

          Node *tmpc = curr1->next;
          curr1->next = curr2->next;
          curr2->next = tmpc;

          curr1->next->next = tmp1;
          curr2->next->next = tmp2;
        }
        else
        {
          Node *tmp1 = curr1->next;
          Node *tmp2 = curr2->next;
          curr1->next = tmp2;
          tmp1->next = tmp2->next;
          tmp2->next = tmp1;
          
          curr2=tmp2;
        }
        swap = 1; 
      }
      

      curr1 = curr1->next;
      curr2 = curr2->next;
    }
    head = start->next;
    free(start);

  } while(swap == 1);
  return head;
}
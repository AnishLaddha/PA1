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
  int start = 1;
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
  printf("Num int read: %d\n", count);
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
  int size = *n_comp;
  printf("size: %d\n",size);
  *n_comp = 0;
  int seq_size = 0;
	long *sequence = Generate_2p3q_Seq(size, &seq_size);
  for(int i = 0; i<seq_size; i++)
  {
    printf("gap_array: %ld\n", sequence[i]);
  }
  printf("seq_size: %d\n",seq_size);
  int gap;
  for(int i = 0; i<seq_size; i++)
  {
    gap = sequence[i];
    printf("GAP: %d\n", gap);
    list = sort_pass(list, gap, n_comp);
    Node* data = list;
    int c = 0;
    while(data != NULL)
    {
      //printf("%ld \n", data->value);
      c++;
      data = data->next; 
    }
    printf("C elements: %d\n", c);
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
    //printf("vals: %ld, %ld\n", curr1->next->value, curr2->next->value);
    //printf("check 1\n");
    while(curr2!=NULL && curr2->next!=NULL)
    {
      
      //printf("am i stuck\n");
    
      if(curr2->next->value < curr1->next->value)
      {
        *n_comp++;
        //swap elements
        //printf("comparing %ld, %ld\n", curr1->next->value, curr2->next->value);
        if(curr1->next != curr2)
        {
          //printf("hi");
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
          //printf("here");

          Node *tmp1 = curr1->next;
          Node *tmp2 = curr2->next;
          curr1->next = tmp2;
          tmp1->next = tmp2->next;
          tmp2->next = tmp1;
        }
        //printf("--comparing %ld, %ld\n", curr1->next->value, curr2->next->value);
        
        swap = 1;
        
      }
      curr1 = curr1->next;
      curr2 = curr2->next;
      //printf("curr2: %ld\n", curr2->value);
    }
    //printf("start: %ld\n", start->next->value);
    head = start->next;
    free(start);
    //printf("head: %ld\n", head->value);
  } while(swap == 1);
  return head;
}
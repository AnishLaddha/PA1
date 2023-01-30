#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"

static int power(int x, int y);
static void insert_sort(long *seq, int size);

long *Generate_2p3q_Seq(int n, int *seq_size)
{
	if(n == 0 || n == 1)
	{
		*seq_size = 0;
	}
	int levels = 1;
	int right = 1;
	while(right<n)
	{
		levels+=1;
		right *=3;
	}
	int seq_num = (levels)*(levels+1)/2;
	*seq_size = seq_num;
	long *arr = (long *) malloc(seq_num * sizeof(long));
	arr[0] = 1;
	int i=1;
	int pow;
	int tmp;
	for(int level = 1; level<levels; level++)
	{
		pow = level;
		while(pow >= 0)
		{
			tmp = power(2,pow) * power(3,(level-pow));
			if (tmp < n)
			{
				arr[i] = tmp;
				i++;
			}
			else
			{
				*seq_size-=1;
			}
			pow -= 1;
		}
	}
	insert_sort(arr, *seq_size);
	return arr;
}

static int power(int x, int y)
{
    int ans = 1;
    for(int i = 0; i<y; i++)
    {
        ans *= x;
    }
    return ans;
}
static void insert_sort(long *seq, int size)
{
	int i,j,temp;
	for(i = 1; i<size; i++)
	{
		temp = seq[i];
		j = i-1;
		while(j>=0 && seq[j]<temp)
		{
			seq[j+1] = seq[j];
			j--;
		}
		seq[j+1] = temp;
	}
}

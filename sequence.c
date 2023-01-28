#include <stdio.h>
#include <sequence.h>

static int power(int x, int y);


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
	long *arr = (long *) malloc(seq_num * sizeof(long));
	arr[0] = 1;
	int i=1;
	int pow;
	for(level = 1; i<levels; i++)
	{
		pow = level;
		while(pow >= 0)
		{
			arr[i] = power(2,pow) * power(3,(level-pow));
			
			pow -= 1;
			i+=1;
		}
	}
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

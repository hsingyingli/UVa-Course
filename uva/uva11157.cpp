#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int max_dist = 0;   //minimized maximum leap
int num, finish;    // number of stone , distance of end
int location[105];  // location of stone
int sizes[105];      // size of stone 1: big ,0: small
int available[105]; // if the stone can stand
char buffer[3];
int frag1 = 0, frag2 = 0;    // location of frag1,2

void initial()
{
	max_dist = 0;
	frag1 = 0;
	frag2 = 0;
	for (int i = 0; i < 105; i++)
	{
		location[i] = 0;
		sizes[i] = 0;
		available[i] = 1;
	}

}

int main()
{
	int cases = 0;
	freopen("11157.in","r",stdin);
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++)
	{
		initial();  // initial value
		scanf("%d %d", &num, &finish); 

		int j = 0;
		for (j = 1; j <= num; j++)
		{
			scanf("%2s%d", buffer, &location[j]);
			if (buffer[0] == 'B')
				sizes[j] = 1;
			else
				sizes[j] = 0;
		}

		location[j] = finish;       // append location of end
		sizes[j] = 1;               // size of the end of location  is BIG

		while (frag1 != j || frag2 != j)
		{
			for (int pos = frag1 + 1; pos <= j; pos++)
			{
				if (available[pos])   // if the position is available
				{
					int dist = location[pos] - location[frag1];         // diff of pos and frag1
					if (dist > max_dist)
						max_dist = dist;

					frag1 = pos;
					if (sizes[pos] == 0)            // if the size of stone is small , available = 0 
						available[pos] = 0;
					break;
				}
			}

			for (int pos = frag2 + 1; pos <= j; pos++)
			{
				if (available[pos])
				{
					int dist = location[pos] - location[frag2];
					if (dist > max_dist)
						max_dist = dist;
					frag2 = pos;
					if (sizes[pos] == 0)
						available[pos] = 0;
					break;
				}
			}
		}

		printf("Case %d: %d\n", i, max_dist);
	}

	return 0;
}
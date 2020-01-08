/*
UVA Practice
student: hsing-ying li
data: 2019/12/22

2d prefix sum
uva 108 Maximum Sum

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
#define max(x,y) ((x)>(y)?x:y)

int matrix[MAX][MAX];
int maxSum = -127 * MAX * MAX;


int main()
{
    int n,i,j,k,l,buffer;

    while(scanf("%d",&n)!=EOF)
    {
        for(i = 0;i<n;i++)
        {
            for(j = 0;j<n;j++)
            {
                scanf("%d",&matrix[i][j]);
                if(i>0) matrix[i][j] +=matrix[i-1][j];              
                if(j>0) matrix[i][j] += matrix[i][j-1];
                if(i>0&&j>0) matrix[i][j] -= matrix[i-1][j-1];
            }
        }


        
        maxSum = -127 * MAX * MAX;

        // dp
        for(i = 0;i<n;i++)
        {
            for(j = 0;j<n;j++)
            {
                for(k = i;k<n;k++)
                {
                    for(l = j;l<n;l++)
                    {
                        buffer = matrix[k][l];
                        if(i>0) buffer -= matrix[i-1][l];
                        if(j>0) buffer -= matrix[k][j-1];
                        if(i>0&&j>0) buffer+= matrix[i-1][j-1];
                        maxSum = max(maxSum,buffer);

                    }

                }

            }
        }

        printf("%d\n",maxSum);




    }
    return 0;
}

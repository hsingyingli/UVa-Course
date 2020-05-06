#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

unsigned int num1,num2,max_length;


int getLength(unsigned int x)
{
    unsigned int counts = 0;
    while(x!=1)
    {
        if(x%2 == 1)
            x = 3*x+1;
        else
            x = x /2;

        counts++;
    }
    return counts+1;

}


int main()
{
    while(scanf("%u %u",&num1,&num2)!=EOF)
    {
        int a , b;
        if(num1 >num2)
        {
            a = num1;
            b = num2;
        }
        else
        {
            a= num2;
            b = num1;
        }
        max_length = 0;
        for(unsigned int i = b;i<=a;i++)
        {
            unsigned int buffer = getLength(i);
            if(max_length < buffer)
                max_length = buffer;
        }
        printf("%u %u %u\n",num1,num2,max_length);
    }

    return 0;
}
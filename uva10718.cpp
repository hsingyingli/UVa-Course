#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

unsigned int N,L,U;

int main()
{
    while(scanf("%u %u %u",&N,&L,&U)!=EOF)
    {
        unsigned int ans = 0;
        for(int i = 31;i>=0;i--)
        {
            unsigned int mask = 1 << i;
            if(N&mask)                          // 1
            {
                unsigned int buffer = ans + mask;
                if(buffer<=L)
                    ans = ans + mask;
            }
            else                                // 0
            {
                unsigned int buffer = ans + mask;
                if(buffer<=U)
                    ans = ans + mask;
            }
        }
        printf("%u\n",ans);

    }

}
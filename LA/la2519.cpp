#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;


struct island
{
    int x;
    int y;
    double left;
    double right;

};

typedef struct island Island;

Island IslandNode[1005];
unsigned int d = 0;
unsigned int num = 0;
int cases = 1;
void sort()
{
    for(int i =0;i<num-1;i++)
    {
        for(int j = i+1;j<num;j++)
        {
            if(IslandNode[i].right>IslandNode[j].right)
            {
                Island buffer = IslandNode[i];
                IslandNode[i] = IslandNode[j];
                IslandNode[j] = buffer;
            }
        }
    }
}

int main()
{
    freopen("./database/2519_in.txt","r",stdin);
    while(scanf("%d %d",&num,&d)&&num&&d)
    {
        int flag = 1;
        int count = 0;
        for(int i = 0;i<num;i++)
        {
            scanf("%d %d",&IslandNode[i].x,&IslandNode[i].y);
            if(IslandNode[i].y>d)   flag = 0;
            IslandNode[i].right = IslandNode[i].x+sqrt(d^2+IslandNode[i].y^2);
            IslandNode[i].left = IslandNode[i].x-sqrt(d^2+IslandNode[i].y^2);
        }
        if(flag)
        {
            sort();
            float start = IslandNode[0].right;
            for(int i = 1;i<num;i++)
            {
                if(IslandNode[i].left > start)
                {
                    start = IslandNode[i].right;
                    count++;
                }

            }
            printf("Case %d: %d\n",cases,count);
        }
        else
            printf("Case %d: -1\n",cases);
        cases++;

    }

}
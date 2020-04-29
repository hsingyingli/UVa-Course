#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct component
{
    int price;
    int quality;

};
vector<component> comp;
vector<int>id;
int main()
{
    freopen("12124.in","r",stdin);
    
    int cases = 0;
    scanf("%d",&cases);
    while(cases--)
    {
        int n , budget,p,q;
        string type,name,buffer;
        scanf("%d %d",&n,&budget);
        for(int i = 0;i<n;i++)
        {
            scanf("%s%s%d%d",type,name,&p,&q);
            if(buffer != type)
                id.push_back(i);
            buffer = type;
        }

        


    }
    return 0;
}
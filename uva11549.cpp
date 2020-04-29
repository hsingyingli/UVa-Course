#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


int buf[10];

int next(int n ,int k)
{
    int ans = 0;
    int l = 0;
    while(k>0)
    {
        buf[l] = k%10;
        k = k/10;
        l++;
    }
    if(n>l) n = l;
    for(int i = 0;i<n;i++)
    {
        ans = ans * 10 + buf[--l];
    }
    return ans;

}



int main()
{
    freopen("./database/11549_in.txt","r",stdin);
    int cases = 0;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        int k1 = k;
        int k2 = k;
        int ans = k;
        do
        {
            k1 = next(n,k1);
            k2 = next(n,k2);
            if(k2 >ans) ans = k2;
            k2 = next(n,k2);
            if(k2 >ans) ans = k2;
        }while(k1!=k2);
        printf("%d\n",ans);

    }
    return 0;
}
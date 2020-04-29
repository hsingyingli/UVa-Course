#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#define max(x,y) ((x)>(y)?x:y)
#define min(x,y) ((x)>(y)?y:x)
using namespace std;




const int maxn = 100005;
int n ,r[maxn],lefts[maxn],rights[maxn];
bool test(int p)
{
    int x = r[1],y = p-r[1];
    lefts[1] = x;
    rights[1] = 0;
    for(int i = 2; i <=n;i++)
    {
        if(i%2 ==1)
        {
            rights[i] = min(y-rights[i-1],r[i]);
            lefts[i] = r[i] - rights[i];
        }
        else
        {
            lefts[i] = min(x - lefts[i-1],r[i]);
            rights[i] = r[i] - lefts[i];
        }

    }
    return (lefts[n]==0);
}

int main()
{
     freopen("./database/1335_in.txt","r",stdin);
    while(scanf("%d",&n)&&n)
    {
        for(int i =1;i<=n;i++)
        {
            scanf("%d",&r[i]);
        }
        if(n==1)
        {
            printf("%d",r[1]);
            continue;
        }
        r[n+1] = r[1];
        int L = 0,R = 0;
        for(int i = 1;i<=n;i++)
        {
                L = max(L,r[i]+r[i+1]);
        }

        if(n%2==1)
        {
            for(int i = 1;i<=n;i++)
            {
                R = max(R,r[i] * 3);
            }
            while(L<R)
            {
                int M = L+(R-L)/2;
                if(test(M)) R = M;
                else L = M+1;
            }
        }
        printf("%d\n",L);
    }
    
    return 0;
}
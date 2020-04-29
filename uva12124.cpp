#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;

struct Component
{
    int price;
    int quality;

};
int cnt,n,budget;

map<string, int>id;
int ID(string s)
{
    if(!id.count(s))
        id[s] = cnt++;
    return id[s];
}

vector<Component>comp[1005];

bool ok(int q)
{
    int sum = 0;
    for(int i = 0;i<cnt;i++)
    {
        int cheapest = budget+1, m = comp[i].size();
        for(int j =0;j<m;j++)
        {
            if(comp[i][j].quality>=q)
            {   
                cheapest = min(cheapest,comp[i][j].price);
            }
        }
        if(cheapest == budget+1) return false;
        sum += cheapest;
        if(sum >budget) return false;
    }
    return true;
}
int main()
{
    freopen("./database/12124.in","r",stdin);
    int cases = 0;
    scanf("%d",&cases);
    cout << cases << "\n";
    while(cases--)
    {
        scanf("%d %d",&n,&budget);
        for(int i = 0;i<n;i++)
        {
            comp[i].clear();
        }
        id.clear();

        int max_q = 0;
        for(int i = 0;i<n;i++)
        {
            char type[30] ,name[30];
            int p,q;
            scanf("%s%s%d%d",type,name,&p,&q);
            max_q = max(max_q,q);
            comp[ID(type)].push_back(Component{p,q});
        }
        int L = 0,R = max_q;
        while(L<R)
        {
            int mid = (L+R+1)/2;
            if(ok(mid)) L = mid;
            else R = mid-1;
        }
        cout <<L;

    }
    return 0;
}
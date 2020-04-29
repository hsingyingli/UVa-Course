#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


vector<int> weight;

int main()
{
    int c , s;
    int cases = 0;
    freopen("./database/410_in(1).txt","r",stdin);
    //freopen("410_out.txt","w+",stdin);
    while(scanf("%d %d",&c,&s)!=EOF)
    {
        weight.clear();
        int total = 0;
        cases++;
        for(int i = 0 ;i<s;i++)
        {
            int buffer;
            scanf("%d",&buffer);
            total += buffer;
            weight.push_back(buffer);
        }
        for(int i = 0;i<(2*c-s);i++)
        {
            weight.push_back(0);
        }
        sort(weight.begin(),weight.end());
        reverse(weight.begin(),weight.end());

        total = total / c;

        printf("Set #%d\n",cases);
        for(int i = 0;i<c;i++)
        {
            printf(" %d: ",i);
            if(weight[i]!=0) printf("%d ",weight[i]);
            if(weight[weight.size()-i-1]!=0) printf("%d ",weight[weight.size()-i-1]);
            printf("\n");
        }
        double ans = 0.0;
        for(int i = 0;i<c;i++)
        {
            ans += abs(total - (weight[i] +weight[weight.size()-i-1] ));
        }


        printf("IMBALANCD = %.5f\n\n",ans);
        

    }


    return 0;
}
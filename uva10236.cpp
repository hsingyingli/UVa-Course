#include<iostream>
using namespace std;

const int maxn = 250000;
const int maxp = 22005;

int fp[maxp];
bool vis[maxn];

int main()
{
    //freopen("./database/10236_in.txt","r",stdin);
    //freopen("result.out","w",stdout);

    long long a=0 ,b=1 ,tmp , i ,j;
    int n , count;

    for(count =1 , i = 2 ; count < maxp ; ++i)
    {
        tmp = a +b;
        a = b;
        b = tmp;
        if(b>=1e10)
        {
            b/=10;
            a/=10;
        }

        if(!vis[i])
        {
            tmp = b;
            while(tmp >=1e9)
                tmp/=10;
            fp[count++] = tmp;
            for( j = i*i;j<maxn;j+=i)
                vis[j] = true;
        }

    }
    fp[1] = 2;
    fp[2] = 3;

    while(cin >> n)
    {
        cout << fp[n]<< endl;
    }

    return 0;
}
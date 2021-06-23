#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
#define N 10007

struct node {
    ll a,b;
}p[N],seg[N];
int n,S;
ll k,D;

int cmp(node ka,node kb) { return ka.b < kb.b; }
bool check(ll x) {
    for(int i=1;i<=n;i++) {
        if(p[i].b-k+x > D) return false;
        double t = (double)(p[i].b-k+x);
        double delta = sqrt((double)D*D-t*t);
        seg[i].a = p[i].a - (ll)delta;
        seg[i].b = p[i].a + (ll)delta;
    }
    sort(seg+1,seg+n+1,cmp);
    int cnt = 1;
    ll R = seg[1].b;
    for(int i=2;i<=n;i++) {
        if(seg[i].a > R) {
            cnt++;
            R = seg[i].b;
        }
    }
    if(cnt > S) return false;
    return true;
}

int main()
{
    int t,cs = 1,i,j;
    freopen("./../database/12255.in","r",stdin); 
    freopen("./../database/12255.out","w",stdout); 	    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%d%d%lld",&k,&n,&S,&D);
        for(i=1;i<=n;i++) cin>>p[i].a>>p[i].b;
        ll low = 0, high = D;
        while(low <= high) {
            ll mid = (low+high)/(ll)2;
            if(check(mid)) low = mid+1;
            else high = mid-1;
        }
        printf("Case %d: ",cs++);
        if(high < 0) puts("IMPOSSIBLE");
        else printf("%lld\n",high);
    }
    return 0;
}

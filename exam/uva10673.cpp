#include<cstdio>
#include<cstdlib>
#define ll long long
int main(){
    ll x, k, T;
    
    freopen("./../database/10673.in","r",stdin);
     
    freopen("./../database/10673.out","w",stdout);
    scanf("%lld",&T);
    while(T--) {scanf("%lld%lld",&x,&k);
     printf("%lld %lld\n",x-x%k,x%k);
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define MAX_N 70
int n, s;
long long dp[MAX_N][MAX_N][2];
int main(){
    freopen("./../database/11420.in", "r", stdin);
    freopen("result.out", "w", stdout);
    while(scanf("%d %d", &n, &s) && n != -1 && s != -1){
        memset(dp, 0, sizeof(dp));
        dp[1][1][1] = 1;
        dp[1][0][0] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= i; j++){
                dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][1];
                dp[i][j][1] += dp[i-1][j][0];
                if(j)
                    dp[i][j][1] += dp[i-1][j-1][1];
            }
        }   
        printf("%lld\n", dp[n][s][1] + dp[n][s][0]);
    }
        
    return 0;
}
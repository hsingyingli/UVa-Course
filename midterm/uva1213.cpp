#include <stdio.h>
#include <stdlib.h>

using namespace std;
int visit[1200] = {0};
int prime[1200];
int dp[1200][15] = {0};

int main()
{
    int prime_count = 0;
    for (int i = 2; i <= 1120; ++i)
    {
        if (!visit[i])
        {
            prime[prime_count++] = i;
            for (int j = i + i; j <= 1120; j += i)
            {
                visit[j] = 1;
            }
        }
    }

    dp[0][0] = 1;
    for (int k = 0; k < prime_count; ++k)
    {
        for (int i = 1120; i >= prime[k]; --i)
        {
            for (int j = 1; j <= 14; ++j)
            {
                dp[i][j] += dp[i - prime[k]][j - 1];
            }
        }
    }
    freopen("./../database/1213.in", "r", stdin);
    freopen("result.out", "w", stdout);
    int n, k;
    while (~scanf("%d%d", &n, &k) && n)
    {
        printf("%d\n", dp[n][k]);
    }

    return 0;
}

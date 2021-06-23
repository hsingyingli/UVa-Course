#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

typedef long long LL;
const int maxn = 510;
int a[maxn][maxn], b[maxn][maxn];
LL dp[maxn][maxn][2];

int main()
{
    int n, m;
    // freopen("./../database/1366.in", "r", stdin);
    freopen("result.out", "w", stdout);
    while (~scanf("%d%d", &n, &m) && (n || m))
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &a[i][j]);
                a[i][j] += a[i][j - 1];
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &b[i][j]);
                b[i][j] += b[i - 1][j];
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]) + a[i][j];
                dp[i][j][1] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + b[i][j];
            }
        }

        printf("%lld\n", max(dp[n][m][0], dp[n][m][1]));
        
    }
    return 0;
}

/*
4 4
0 0 10 9
1 3 10 0
4 2 1 3
1 1 20 0
10 0 0 0
1 1 1 30
0 0 5 5
5 10 10 10
0 0*/
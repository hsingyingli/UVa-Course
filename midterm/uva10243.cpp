#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;
#define MAX_N 1005
#define MIN(x, y) (((x)>(y))? (y): (x))
int N;
vector<int>nodes[MAX_N];
int dp[MAX_N][2];


void dfs(int, int);
int main()
{
    freopen("./../database/10243.in", "r", stdin);
    freopen("result.out", "w", stdout);
    
    while(scanf("%d", &N)!= EOF && N){
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < MAX_N; i++){
            nodes[i].clear();
        }
        for(int i = 1; i <= N; i++){
            int n;
            scanf("%d", &n);
            for(int j = 0; j <n; j++){
                int tmp;
                scanf("%d", &tmp);
                nodes[i].push_back(tmp);
            }
        }
        dfs(1, -1);
        printf("%d\n", MIN(dp[1][1], dp[1][0]) );
    }

    return 0;
}


void dfs(int node, int from){
    dp[node][1] = 0;
    dp[node][0] = 0;
    for(int i = 0; i <nodes[node].size(); i++){
        int children = nodes[node][i];

        if(children == from)
            continue;
        dfs(children, node);

        dp[node][0] += dp[children][1];
        dp[node][1] += MIN(dp[children][1], dp[children][0]); 
    }
    dp[node][1]++;
}


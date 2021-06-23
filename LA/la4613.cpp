#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 205
#define INF 1e6
#define MIN(x, y) (((x) > (y))? (y) : (x))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int cases, N;
int dp[MAX_N][MAX_N][2];

struct interval{
    int arrive;
    int during;
};

vector<struct interval> fromLeft;
vector<struct interval> fromRight;
void initial();
void getCar();
void solve();


int main()
{
    freopen("./../database/4613.in", "r", stdin);
    freopen("result.out", "w", stdout);
    scanf("%d", &cases);
    for(int i = 0; i <cases; i++){
        initial();
        fromLeft.clear();
        fromRight.clear();
        scanf("%d", &N);
        getCar();
        solve();
       
        }   
    return 0;
}

    


void initial(){
    for(int i = 0; i <MAX_N; i++){
        for(int j = 0; j < MAX_N; j++){
            for(int k = 0;k<2;k++){
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = dp[0][0][1] = 0;
}

void getCar(){
    char direction[5];
    struct interval tmp;
    for(int i = 0 ; i < N; i++){
        scanf("%S%d%d", &direction, &tmp.arrive, & tmp.during);
        if(direction[0] == 'A')
            fromLeft.push_back(tmp);
        else
            fromRight.push_back(tmp);
    }
}

void solve()
{
    int n = fromLeft.size();
    int m = fromRight.size();

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            int t1 = dp[i][j][0], t2 = 0;
            for(int k = j+1; k<=m;k++){
                t1 = MAX(t1, fromRight[k-1].arrive);
                t2 = MAX(t2, t1 + fromRight[k-1].during);
                dp[i][k][1] = MIN(dp[i][k][1], t2);
                t1+=10;
                t2+=10;
            }
            t1 = dp[i][j][1], t2 = 0;
            for(int k = i+1; k<=n;k++){
                t1 = MAX(t1, fromLeft[k-1].arrive);
                t2 = MAX(t2, t1 + fromLeft[k-1].during);
                dp[k][j][0] = MIN(dp[k][j][0], t2);
                t1+=10;
                t2+=10;
            }
        }
        
    }
    printf("%d\n", MIN(dp[n][m][1] , dp[n][m][0]));
}
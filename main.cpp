#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 205
#define INF 1e6
#define MAX(X, Y) (((X)>(Y))?(X):(Y) )
#define MIN(X, Y) (((X)>(Y))?(Y):(X) )
#define ABS(X) ((X)>0?(X):(-X))


struct interval{
    int arrive;
    int during;
    interval(int a, int b):arrive(a), during(b){};
};


vector<struct interval> fromLeft;
vector<struct interval> fromRight;

int dp[MAX_N][MAX_N][2];
int N;

void initial();
void getCar();
void solve();


int main(){
    freopen("./database/4613.in", "r", stdin);
    freopen("result.out", "w", stdout);
    int cases = 0;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &N);
        initial();
        getCar();
        solve();
    }

    return 0;
}

void initial(){
    fromLeft.clear();
    fromRight.clear();
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j < MAX_N; j++){
            dp[i][j][0] = INF;
            dp[i][j][1] = INF;
        }
    }
    dp[0][0][0] = dp[0][0][1] = 0;
}

void getCar(){
    char dir[5];
    int a, b;
    for(int i = 0; i< N; i++){
        scanf("%s%d%d", &dir, &a, &b);
        if(dir[0] == 'A')
            fromLeft.push_back(interval(a, b));
        else
            fromRight.push_back(interval(a, b));
    }
}

void solve(){
    int n_left = fromLeft.size();
    int n_right = fromRight.size();

    for(int i = 0; i <= n_left; i++){
        for(int j = 0; j <= n_right; j++){
            int t1 = dp[i][j][0], t2 = 0;
            for(int k = j+1; k <= n_right; k++){
                t1 = MAX(t1, fromRight[k-1].arrive);
                t2 = MAX(t2, t1+fromRight[k-1].during);
                dp[i][k][1] = MIN(dp[i][k][1], t2);
                t1 +=10;
                t2 +=10;
            }

            t1 = dp[i][j][1], t2 = 0;
            for(int k = i+1; k <= n_left; k++){
                t1 = MAX(t1, fromLeft[k-1].arrive);
                t2 = MAX(t2, t1+fromLeft[k-1].during);
                dp[k][j][0] = MIN(dp[k][j][0], t2);
                t1 +=10;
                t2 +=10;
            }
        }
    }
    printf("%d\n", MIN(dp[n_left][n_right][1], dp[n_left][n_right][0]));
}
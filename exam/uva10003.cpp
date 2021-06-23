#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;
#define MIN(x, y) (((x)>(y))?(y):(x))
#define MAX(x, y) (((x)>(y))?(x):(y))
#define MAX_C 55
#define INF 99999

int length;
int numOfCut;
int dp[MAX_C][MAX_C];
vector<int>cut;


void initial();
void solve();
int main(){
    freopen("./../database/10003.in","r",stdin);
    freopen("result.out","w",stdout);
    
    while(scanf("%d", &length) && length) {
        initial(); 
        solve();
    }

    return 0;
}

void initial() {
    memset(dp, 0, sizeof(dp));
    cut.clear();
    cut.push_back(0);

    scanf("%d", &numOfCut);
    for(int i=0; i<numOfCut; i++) {
        int c = 0;
        scanf("%d", &c);
        cut.push_back(c);
    }
    cut.push_back(length); 
}


void solve() {

    for(int i=2; i<numOfCut+2; i++) {
        int left = 0;
        int right = i;
        while(right<numOfCut+2) {
            int min = INF;
            for(int mid=left+1; mid<right; mid++) {
                min = dp[left][mid] + dp[mid][right] < min ? dp[left][mid] + dp[mid][right] : min;
            }

            if(min!=INF) {
                dp[left][right] = min+cut[right] - cut[left];
            }
            left+=1;
            right+=1;
        }
    }
    printf("The minimum cutting is %d.\n", dp[0][numOfCut+1]);
}
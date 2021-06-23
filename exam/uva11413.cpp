#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
#define MIN(x, y) (((x)>(y))?(y):(x))
#define INF 99999
int M, N;
vector<int>containers;


void init();
void solve();
int cal(int);

int main() {
    freopen("./../database/11413.in","r",stdin);
    freopen("result.out","w",stdout);
    while(scanf("%d %d", &M, &N)!=EOF) {
        init();
        solve();
    }


    return 0;
}

void init() {
    containers.clear();
}

void solve() {
    int left = -1;
    int right= 0;
    int result = -1;

    for(int i=0; i<M; i++) {
        int tmp=0;
        scanf("%d", &tmp);
        containers.push_back(tmp);
        left = tmp>left?tmp:left;
        right+=tmp;
    }

    while(left<=right) {
        int mid = (right+left)/2;
        int num = cal(mid);
        if(num>N){
            left=mid+1;
        }
        else{
            right=mid-1;
            result=mid;
        }
    }
    printf("%d\n", result);
}

int cal(int volume) {
    int cnt=1;
    int sum=0;
    for(int i=0; i<M; i++) {
        sum += containers[i];
        if(sum>volume){
            sum = containers[i];
            cnt++;
        }
    }
    return cnt;
}
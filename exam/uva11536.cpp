#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MIN(x, y) (((x)>(y))?(y):(x))

#define MAX 1000005
#define INF 9999999


int cases;
int N, M, K;

int visited[MAX];
int array[MAX];

void init();
void solve();

int main() {
    freopen("./../database/11536.in","r",stdin);
    freopen("result.out","w",stdout);
    
    scanf("%d", &cases);
    for(int i=0; i<cases; i++) {
        scanf("%d %d %d", &N, &M, &K);
        printf("Case %d: ", i+1);
        init();
        solve();
    }


    return 0;
}



void init() {
    memset(array, 0, sizeof(array));
    memset(visited, 0, sizeof(visited));
    array[1]=1; array[2]=2; array[3]=3;
    
    for(int i=4; i<=N; i++) {
        array[i] = (array[i-1]+array[i-2]+array[i-3]) %M+1;
    }

}

void solve() {
    int left=1, right=1, cnt=0, min= INF;
    while(right<=N) {
        int num = array[right++];
        visited[num]++;
        if(num<=K && visited[num]==1) {
            cnt++;
        }
        while(cnt==K && left<right){
            min = MIN(min, right-left);
            num = array[left++];
            visited[num]--;
            if(num<=K && visited[num]==0)
                cnt--;
        }
    }
    if(min<N)
        printf("%d\n", min);
    else
        printf("sequence nai\n");
}
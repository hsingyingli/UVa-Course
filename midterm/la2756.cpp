#include<cstdio>
#include<cstdlib>

using namespace std; 

int N;

void solve();
int get_times(int);

int main(){
    freopen("./../database/2756.in", "r", stdin);
    freopen("result.out", "w", stdout);
    int cases = 0;
    scanf("%d", &cases);
    for(int i =0; i <cases; i++){
        scanf("%d", &N);
        solve();
    }
    return 0;
}




int get_times(int n){
    return (n)*(n-1)/2;
}

void solve(){
    int result = 0;
    if(N%2==0){
        result = get_times(N/2)*2;
    }
    else{
        result += get_times((N-1)/2);
        result += get_times((N+1)/2);
    }
    printf("%d\n", result);
}
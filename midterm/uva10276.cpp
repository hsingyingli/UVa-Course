#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

int board[55];

void solve();

int main(){
    freopen("./database/10276.in", "r", stdin);
    int cases = 0;
    scanf("%d", &cases);
    solve();
    for(int i = 0; i < cases; i++){
        int query = 0;
        scanf("%d", &query);
        printf("%d\n", board[query]);
    }
    return 0;
}




void solve(){
    board[1] = 1;
    board[2] = 3;
    int gap = 4;
    int cnt = 0;
    for(int i = 3; i < 55; i++){
        board[i] = board[i-1] + gap;
        cnt++;
        if(cnt == 2){
            cnt = 0;
            gap +=2;
        }
    }



}
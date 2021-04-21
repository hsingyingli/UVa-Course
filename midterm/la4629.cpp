#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;
#define MIN(x, y) (((x) > (y)) ? (y) :(x))
#define MAX_COL 1000005
#define INF 99999
vector<vector<int>> boards;
int row, col;
int moves[MAX_COL];
int pass[MAX_COL];
int moveLeft[MAX_COL];
int moveRight[MAX_COL];

void solve();
void getLeft(int);
void getRight(int);
void calculate(int);
void initial();

int main(){
    freopen("./../database/4629.in", "r", stdin);
    freopen("result.out", "w", stdout);
    int cases;
    scanf("%d", &cases);
    while(cases--){
        initial();
        
        scanf("%d %d", &row, &col);
        for(int i= 0; i <row; i++){
            vector<int>tmp;
            int n, t;
            scanf("%d", &n);
            for(int j = 0; j < n; j++){
                scanf("%d", &t);
                tmp.push_back(t);
            }
            boards.push_back(tmp);
        }
        solve();
    }


    return 0;
}


void initial(){
    boards.clear();
    memset(pass, 0, sizeof(pass));
    for(int i= 0 ; i < MAX_COL ; i++){
        moveLeft[i]  = INF;
        moveRight[i] = INF;
        moves[i]     = INF;
    }
}

void getLeft(int now){
    for (int i = 0; i < MAX_COL; i++)
    {
        moveLeft[i] = INF;
    }
    int n_col = 0;
    for (int i = 0; i < boards[now].size(); i++)
    {
        if (boards[now][i] == 0)
        {
            moveLeft[n_col] = 0;
            n_col++;
        }
        else
        {
            for (int j = 0; j < boards[now][i]; j++)
            {
                int cnt = 0;
                int target = boards[now][i] - j;
                for(int k = i; k >=0; k--){
                    if(boards[now][k] == 0){
                        target--;
                    }
                    else
                        cnt++;
                    if(target == 0)
                        break;
                }
                if(target == 0)
                    moveLeft[n_col] = cnt;
                n_col++;
            }
        }
    }
}

void getRight(int now){
    for (int i = 0; i < MAX_COL; i++)
    {
        moveRight[i] = INF;
    }
    int n_col = col-1;
    for (int i = boards[now].size()-1; i >=0; i--)
    {
        if (boards[now][i] == 0)
        {
            moveRight[n_col] = 0;
            n_col--;
        }
        else
        {
            for (int j = 0; j < boards[now][i]; j++)
            {
                int cnt = 0;
                int target = boards[now][i] - j;
                for (int k = i; k < boards[now].size(); k++)
                {
                    if (boards[now][k] == 0)
                    {
                        target--;
                    }
                    else
                        cnt++;
                    if (target == 0)
                        break;
                }
                if (target == 0)
                    moveRight[n_col] = cnt;
                n_col--;
            }
        }
    }
}

void calculate(int now){
    // printf("\n+++++++++++++\n");
    getLeft(now);
    // for(int i = 0; i < col; i++){
    //     printf("%d ", moveLeft[i]);
    // }
    // printf("\n-----------------\n");
    getRight(now);
    // for (int i = 0; i < col; i++)
    // {
    //     printf("%d ", moveRight[i]);
    // }
    // printf("\n-----------------\n");
    for(int i = 0; i < col;i++){
        moves[i] = MIN(moveLeft[i], moveRight[i]);
    }
    for(int i = 0; i < col; i++){
        if(moves[i] != INF)
            pass[i]++;
    }
}



void solve(){
    vector<int> ans= {};
    vector<int> buffer = {};
    for(int i = 0; i < row; i++){
        calculate(i);
    }
    for(int i = 0; i<col; i++){
        if(pass[i] == row)
            buffer.push_back(i);
    }
    int m = INF;
    for(int i = 0; i < buffer.size(); i++){
        if(moves[i] < m )
            m = moves[i];
    }
    for(int i = 0; i < buffer.size(); i++){
        if(moves[i] == m)
            ans.push_back(i);
    }
    printf("%d\n", m);
    for(int i = 0; i < ans.size(); i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
    
}
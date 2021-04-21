#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define MAX_CITY 500
#define INF 1e9
using namespace std;

int citys, from, to, cases = 0;
int road[MAX_CITY][MAX_CITY];
int path[MAX_CITY][MAX_CITY];


void initial();
void CreateMap();
void FloydAlgorithm();
void get_path(int, int);

int main()
{
    freopen("./database/00341.in", "r", stdin);
    while(scanf("%d", &citys) && citys){
        initial();
        CreateMap();
        FloydAlgorithm();
        cin >> from >> to;
    
        printf("Case %d: Path =", ++cases);
        get_path(from, to);
        printf("; %d second delay\n", road[from][to]);
    }
   
    return 0;
}

void initial(){
    for(int i = 0; i < MAX_CITY; i++){
        for(int j = 0; j <MAX_CITY; j++){
            road[i][j] = INF;
            path[i][j] = i;
        }
    }
}

void CreateMap(){
    for (int i = 1; i <= citys; i++)
    { 
        int n = 0;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            int neightbor, cost;
            cin >> neightbor >> cost;
            road[i][neightbor] = cost;
        }
        road[i][i] = 0;
    }

   
}

void FloydAlgorithm(){
    int i, j, k;
    for(k = 1; k<= citys;k++){
        for(i = 1; i <= citys;i++){
            for(j = 1; j<= citys; j++){
                if(road[i][j] > (road[i][k] + road[k][j]) ){
                    road[i][j] = road[i][k] + road[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }  
}

void get_path(int a, int b)
{
    if(a!=b)
        get_path(a, path[a][b]);
    printf(" %d",b);
    
}
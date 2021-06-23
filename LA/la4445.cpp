#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;
int N;  // num of airplane

struct interval{
    int a;
    int b;
};


vector<struct interval> airplane;
void input();

int main(){
    freopen("./database/4445.in", "r", stdin);
    while(scanf("%d", &N) &&N){
        airplane.clear();
        input();
    
    }
    return 0;
}


void input(){
    for(int i = 0; i <N; i++){
        struct interval tmp;
        scanf("%d %d", &tmp.a, &tmp.b);
        airplane.push_back(tmp);
    }

    for(int i = 0; i < N; i++){
        
    }


}
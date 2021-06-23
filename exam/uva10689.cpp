#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
#define MAX_N 99999

#define MIN(x, y) (((x)>(y))?(y):(x))
#define MAX(x, y) (((x)>(y))?(x):(y))

typedef long long ll;

struct Matrix{
    int row, col;
    ll num[2][2];
};


typedef struct Matrix Matrix;


ll a, b, n, m;
int cases;

Matrix solve(Matrix, ll, int);
Matrix cal(Matrix, Matrix, int);

int main(){
    freopen("./../database/10689.in","r",stdin);
    freopen("result.out","w",stdout);
    scanf("%d", &cases);
    
    Matrix base;
    base.row = base.col = 2;
    base.num[0][0] = base.num[0][1] = base.num[1][0] = 1;
    base.num[1][1] = 0;
    for(int i=0; i<cases; i++) {
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
        if( n==0)
            printf("%lld\n", a);
        else if (n == 1){
            printf("%lld\n", b);
        }
        else{
            Matrix ans = solve(base, n-1, (int)(pow(10, m)));
            printf("%lld\n", (ans.num[0][0]*b + ans.num[0][1]*a)% (int)(pow(10, m)));
        }
    }

   
    return 0;
}

Matrix solve(Matrix m, ll k, int mod) {
    
    Matrix ans;
    ans.row = ans.col = 2;
    ans.num[0][0] = ans.num[1][1] = 1;
    ans.num[0][1] = ans.num[1][0] = 0;
    while(k){
        if (k&1)
            ans = cal(ans, m, mod);
        m = cal(m, m, mod);
        k>>=1;
    }
    return ans;
}

Matrix cal(Matrix ma, Matrix mb, int mod) {
    Matrix ans;
    ans.row = ma.row; ans.col = mb.col;
    memset(ans.num, 0, sizeof(ans.num));
    for(int i=0; i<ma.row; i++) {
        for(int j=0; j<mb.col; j++) {
            for(int k=0; k<ma.col; k++) {
                ans.num[i][j] = (ans.num[i][j] + ma.num[i][k] * mb.num[k][j])%mod;
            }
        }
    }
    return ans;

}



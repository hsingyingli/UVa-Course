#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
#define MAX_N 99999

#define MIN(x, y) (((x)>(y))?(y):(x))
#define MAX(x, y) (((x)>(y))?(x):(y))


int digits[MAX_N];


// a/b
int a = 1;
int b = 1;
int num = 0;
int N = 0;

void initial();
void solve();
int gcd(int, int);



int main(){
    freopen("./../database/911.in","r",stdin);
    freopen("result.out","w",stdout);
    
    while(cin>>N) {
        cin >> num;
        // initialize
        
        initial();
        solve();
       
        for(int i=2; i<=N; i++) {
            a*=digits[i];
        }
        printf("%d\n", a/b);
    }
    return 0;
}

void initial() {
    
    for(int i=0; i<=N; i++) {
        digits[i] = i;
    }
   
    a = 1;
    b = 1;
}

void solve() {
    
    for(int i=0; i<num; i++) {
        int tmp = 0;
        cin >> tmp;
       
        for(int j=2; j<=tmp; j++) {
            int buffer = j;
            for(int k=2; k<=N; k++) {
                int cd = gcd(digits[k], buffer);
                buffer/=cd;
                digits[k]/=cd;
                if(buffer == 1)
                    break;
            }
            b*=buffer;
        }
    }
}

int gcd(int n1, int n2) {
    if(n1<n2) {
        int buf = n2;
        n2 = n1;
        n1 = buf;
    }
    int r, q;
    while(n2 != 0) {
        r = n1 /n2;
        q = n1 % n2;
        n1 = n2;
        n2 = q;
    }
    return n1;



    /*
    24 / 16 = 1 ....8
    16  / 8 = 2 ...0 
    8 / 0 
    */

}

#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

#define MIN(x, y) (((x)>(y))?(y):(x))
#define MAX(x, y) (((x)>(y))?(x):(y))
#define INF 9999999

typedef long long ll;

ll N, c1, c2, n1, n2, r, x, y;

void gcd(ll, ll, ll &, ll &, ll&);
void solve();
int gcd(int, int);
int main() {
    // freopen("./../database/10090.in","r",stdin);
    // freopen("result.out","w",stdout);
    while(scanf("%lld", &N) && N){ 
        scanf("%lld %lld", &c1, &n1);
        scanf("%lld %lld", &c2, &n2);
        gcd(n1, n2, r, x, y);
        // printf("%lld, %lld, %lld, %lld, %lld, %lld, %lld\n", c1, c2, n1, n2, r, x, y);
        // ll lower = ceil(-1.0 * N * x / n2); 
		// ll upper = floor(1.0 * N * y / n1);
			
		// if (N % r || lower > upper) {
		// 	puts("failed");
		// }else if (c1 * n2 >= c2 * n1) {
		// 	x = x * N / r + n2 / r * lower;
        //     y = y * N / r - n1 / r * lower;
        //     printf("%lld %lld\n", x, y);
		// }else {
		// 	x = x * N / r + n2 / r * upper;
        //     y = y * N / r - n1 / r * upper;
        //     printf("%lld %lld\n", x, y);
		// }
    }
    return 0;
}


void gcd(ll a, ll b, ll &r, ll &x, ll &y) {
    if(!b) {
        r = a;
        x = 1;
        y = 0;
    }
    else {
        gcd(b, a%b, r, y, x);
        y-=(a/b)*x;
    }
}

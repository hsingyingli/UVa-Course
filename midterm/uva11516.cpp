#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) > (Y)) ? (Y) : (X))
#define ABS(X) ((X) > 0 ? (X) : (-X))

int N, M;
vector<int> houses = {};

int getAP(int, int);
void solve();

int main()
{
    freopen("./../database/11516.in", "r", stdin);
    freopen("result.out", "w", stdout);
    int cases = 0;
    scanf("%d", &cases);

    while (cases--)
    {
        houses.clear();
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++)
        {
            int a = 0;
            scanf("%d", &a);
            houses.push_back(a);
        }
        sort(houses.begin(), houses.end());
        solve();
    }

    return 0;
}

int getAP(int distance)
{
    int pos, n_aps = 1;
    pos = houses[0] + distance;
    for (int i = 1; i < houses.size(); i++)
    {
        if (houses[i] > pos)
        {
            n_aps++;
            pos = houses[i] + distance;
        }
    }
    return n_aps;
}

void solve()
{
    int left = 0;
    int right = (houses[M - 1] - houses[0] + 1) * 2;

    while (left < right)
    {
        int mid = (left + right) / 2;
        int n_aps = getAP(mid);
        if (n_aps > N)
            left = mid + 1;
        else
            right = mid;
    }
    printf("%.1f\n", right / 2.00);
}
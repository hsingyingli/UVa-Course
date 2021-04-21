#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;


struct interval{
    int left;
    int right;
    interval(int l, int r):left(l), right(r){};
};

int M;
vector<struct interval> lines;
vector<struct interval> result;
void sortLines();
void solve();

int main(){
    freopen("./../database/10020.in", "r", stdin);
    freopen("result.out", "w", stdout);
    int cases;
    int left, right;
    scanf("%d", &cases);
    for(int i = 0 ; i <cases; i++)
    {
        if(i!=0)
            printf("\n");
        lines.clear();
        result.clear();
        scanf("%d", &M);
        while(scanf("%d %d", &left, &right) && (left ||right) )
        {
            lines.push_back(interval(left, right));
        }
        sortLines();
        solve();
    }
    return 0;
}

void sortLines(){
    for(int i = 0; i < lines.size()-1; i++)
    {
        for(int j = i+1; j< lines.size(); j++)
        {
            if(lines[i].left > lines[j].left)
            {
                struct interval tmp = lines[i];
                lines[i] = lines[j];
                lines[j] = tmp;
            }
        }
    }
}


void solve(){
    int requireRight = 0;
    int requireLeft  = 0; 
    for(int i = 0; i < lines.size(); i++)
    {
        if(lines[i].left <= requireLeft && lines[i].right >requireLeft)
        {
           
            struct interval best = lines[i];
            requireRight = lines[i].right;
            for(int j = i+1; j< lines.size(); j++)
            {
                if(lines[j].left <= requireLeft && lines[j].right>requireRight)
                {
                    requireRight = lines[j].right;
                    best = lines[j];
                }
            }
            result.push_back(best);
        }
        requireLeft = requireRight;
        if(requireLeft>=M)
            break;
    }

    if(result.size() != 0 && result[result.size()-1].right >= M)
    {
        printf("%d\n", result.size());
        for(int i = 0; i < result.size(); i++){
            printf("%d %d\n", result[i].left, result[i].right);
        }
    }
    else
        printf("0\n");
}
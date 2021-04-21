#include<iostream>
#include<vector>

using namespace std;

vector<int>rain;
vector<int>n_rain;
int n , m;    // n: num of pool  , m : nun of day


void solve()
{
    for(int i = 0 ; i< rain.size();i++)
    {
        if(rain[i] == 0)
        {
            n_rain.push_back(i);
        }
        else
        {
            for(int j = i+1 ; j < rain.size();j++)
            {
                if(rain[j] ==0 )
                {   
                    n_rain.push_back(j);
                    break;
                }
            }

        }     
    }





}




int main()
{
    freopen("./database/1623_in_txt","r",stdin);
    freopen("result.out" , "w",stdout);
    int cases = 0;
    cin >> cases;
    while(cases--)
    {
        cin >> n>>m;
        rain.clear();
        n_rain.clear();

        for(int i = 0; i < m;i++)
        {
            int temp = 0;
            cin >> temp;
            rain.push_back(temp);
        }
        rain.push_back(0);
        solve();

    }
    return 0;
}
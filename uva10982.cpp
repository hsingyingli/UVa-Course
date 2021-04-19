#include<iostream>
#include<vector>
using namespace std;
int n,m;
int v[110];
int pairs[110][110];
vector<int>class1;
vector<int>class2;



void clear()
{
    class1.clear();
    class2.clear();
    
    for(int i = 0 ; i < 110 ; i++)
    {
        for(int j = 0 ; j < 110 ; j++)
        {
            pairs[i][j] = 0;
        }
        v[i] = 0;
    }

}


int _sum()
{
    int counts = 0;
    for(int i = 0 ; i < class1.size()-1;i++)
    {
        for(int j = i+1;j<class1.size();j++)
        {
            if(pairs[class1[i]][class1[j]])
                counts++;
        }
    }
    for(int i = 0 ; i < class2.size()-1;i++)
        {
            for(int j = i+1;j<class2.size();j++)
            {
                if(pairs[class2[i]][class2[j]])
                    counts++;
            }
        }
        return counts; 
}

void solve(int cases)
{
    int num = 0;
    for(int i = 1 ; i <= n;i++)
    {
        int t1 = 0 , t2 = 0;
        for(int j = 1 ; j <=n;j++)
        {
            if(v[j] == 1 && pairs[i][j]) t1++;
            if(v[j] == 2 && pairs[i][j]) t2++;
        }
        if(t1 > t2)
        {
            v[i] = 2;
            num += t2;
            class2.push_back(i);
        }
        else
        {
            v[i] = 1;
            num+=t1;
            class1.push_back(i);   
        }
    }
    
    if(num>(m/2) )
        cout << "Case #"<<cases<<": Impossible."<<endl;
    else
    {
        cout << "Case #"<<cases<<": "<<class1.size()<<endl;
        for(int i = 0 ; i <class1.size();i++)
        {
            cout << class1[i]<< " ";
        }
        cout << endl;
    }

}





int main()
{
    freopen("./database/10982_in.txt","r",stdin);
    freopen("result.out","w",stdout);

    int cases;

    cin >> cases;
    for(int i = 1; i <=cases ; i++)
    {
        cin >> n >> m;
        clear();
        for(int j = 0 ; j < m ; j ++)
        {
            int a,b;
            cin >> a>>b;
            pairs[a][b] = pairs[b][a] = 1;
        }
        solve(i);
    }
    return 0;
}

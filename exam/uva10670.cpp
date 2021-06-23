#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct company{
    string name;
    int a;
    int b;
    int cost;
};

typedef struct company company;
vector<company>companys;
int N, M, L;

void get_input();
int greedy(int, int);
void solve();
int compare(company, company);

int main(){
    freopen("./../database/10670.in","r",stdin);
    freopen("result.out","w",stdout);
    int cases = 0;
    cin >> cases;
    for(int i=0; i<cases; i++) {
        companys.clear();
        cin >> N >> M >> L;
        cout<<"Case "<<i+1<<"\n";
        
        for(int j=0; j<L; j++) {
            get_input();
        }
        solve();
    }
    return 0;
}

int compare(company A, company B) {
	if (A.cost != B.cost) {
		return A.cost < B.cost;
	}
	for(int i=0; i<A.name.length() && i <B.name.length(); i++) {
        if(A.name[i]-B.name[i]>0) {
            return 0;
        }
        else if(A.name[i]-B.name[i]<0) {
            return 1;
        }
    }
    return 0;
}


void solve() {
    sort(companys.begin(), companys.end(), compare);
    for(int i=0; i<companys.size(); i++) {
        cout << companys[i].name << " "<< companys[i].cost<<endl;
    }
}

int greedy(int a, int b) {
    int num_of_work = N;
    int total_cost = 0;
    while(num_of_work != M) { 
        if(num_of_work /2 < M) {
            total_cost+=a;
            num_of_work--;
        }
        else {
            int tmp = (num_of_work-num_of_work/2)*a;
            if(b<tmp)
                total_cost+=b;
            else
                total_cost+=tmp;
            num_of_work/=2;
        }

    }
    return total_cost;
}

void get_input() {
    string str;
    int a, b, num=0, idx=0;
    int flag = 1;
    cin >> str;
    
    for(int i=0; i <str.length(); i++) {
        if(flag) {
            if(str[i]==':'){
                flag=0;
            }
            else{
                idx++;
            }
        }
        else {
            if(str[i]==',') {
                a = num;
                num=0;
            }
            else
                num = num*10+str[i]-48;
        }
        
    }
    b = num;
    company tmp;
    tmp.name = tmp.name.assign(str, 0, idx);
    tmp.a = a;
    tmp.b = b;
    tmp.cost = greedy(a, b);
    companys.push_back(tmp);
}
/*
2
100 5 3
A:1,10
B:2,5
C:3,1

1123 1122 5
B:50,300
A:1,1000 
C:10,10
D:1,50
E:0,0
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include<algorithm>
using namespace std;

#define MAX 1505
#define min(x,y) ((x)>(y)?y:x)

int visited[MAX];				/*if node is visited :1     not visited : 0*/
vector<int> node[MAX];			/*stoe the nodes status*/
int num;
int dp[MAX][2];					/* dp[x][0] store the number of soldiers that the node didnt place soldier 
								,  dp[x][1] store the number of soldiers that the node place soldier*/

void find();					/*find the min amount of soldiers*/
void dfs(int n);				/*do the depth first search*/

int main()
{
	int n, amount, buffer,i;
	while (scanf("%d", &num) != EOF)
	{
		memset(node, 0, sizeof(node));
		for(i = 0;i<num;i++)
		{
			
			scanf("%d%*c%*c%d%*c", &n, &amount);
			while (amount--)
			{
				scanf("%d", &buffer);
				node[n].push_back(buffer);	/*buffer is connected with n*/
				node[buffer].push_back(n);
			}
		}
		find();
	}
	return 0;
}


void find()
{
	int ans = 0;
	int i;
	memset(visited, 0, sizeof(visited));  /* inital to 0*/
	for (i = 0; i < num; i++)
	{
		if (visited[i] != 1)				/*if the node is not visited*/
		{
			dfs(i);
			ans = ans + min(dp[i][0], dp[i][1]);
		}
	}
	printf("%d\n", ans);
}

void dfs(int n)
{
	int i, next;

	visited[n] = 1;
	dp[n][0] = 0;
	dp[n][1] = 1;

	for (i = 0; i < node[n].size(); i++)			
	{
		next = node[n][i];
		if (visited[next] != 1)
		{
			dfs(next);
			dp[n][0] += dp[next][1];
			dp[n][1] += min(dp[next][1], dp[next][0]);
		}
	}
}
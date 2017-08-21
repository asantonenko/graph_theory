#include <iostream>

#include<vector>
#include<algorithm>
#include<cassert>


using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n;

int graph[50][50];

int color[50] = {WHITE};

bool dfs (int v, int p)
{
	if (color[v]==GRAY)
	{
		return true;
	}
	if (color[v]==BLACK)
		return false;
	color[v] = GRAY;
	for (int next=0; next<n; next++)
		if (next != p && graph[v][next]) 
			if (dfs(next, p)) return true;
	color[v] = BLACK;
	return false;
}

int main()
{
	
	cin >>n;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >>graph[i][j];
		}
	
	bool has_cycle = false;
	
	for (int i = 0; i < n; i++)
	{
		if(dfs(i, -1)) 
		{
			has_cycle = true;
			break;
		}
	}
	
	cout <<has_cycle <<endl;
	
	return 0;
}
#include <iostream>

#include<vector>
#include<algorithm>
#include<cassert>


using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n;

int graph[100][100];

int color[100] = {WHITE};

void dfs (int v)
{
	if (color[v]!=WHITE)
		return;
	color[v] = GRAY;
	for (int next=0; next<n; next++)
		if (graph[v][next]) 
			dfs(next);
	color[v] = BLACK;
}

int main()
{
	int s;
	
	cin >>n >>s;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >>graph[i][j];
		}
		
	dfs ( s - 1 );
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		assert(color[i]!=GRAY);
		if (color[i]==BLACK)
			cnt++;
	}
	
	cout <<cnt <<endl;
	
	return 0;
}
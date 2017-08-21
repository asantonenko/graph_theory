#include <iostream>

#include<vector>
#include<algorithm>
#include<cassert>
#include<queue>


using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n;

short graph[1000][1000];


int main()
{
	int x;
	
	cin >>n >>x;
	x--;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >>graph[i][j];
		}
	
	
	vector<int> dist(n,-1);
	
	queue<int> q;
	
	
	dist[x] = 0;
	q.push(x);
	
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		//cout <<"take " <<v <<endl;
		for (int next=0;next<n;next++)
		{
			if (graph[v][next] && (dist[next] == -1))
			{
				q.push(next);
				dist[next] = dist[v] + 1;
				//cout <<"push " <<next <<" ( dist = " <<dist[next] <<")" <<endl;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		cout <<dist[i]<<" ";
	}
	
	cout <<endl;
	
	return 0;
}
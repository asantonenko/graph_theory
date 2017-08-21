#include <iostream>

#include<vector>
#include<algorithm>
#include<cassert>
#include<queue>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;


int main()
{
	int n,m;
	
	cin >>n >>m;
	
	vector < vector <int> > link(n);
	
	int a, b;
	cin >> a >>b;
	a--;b--;
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >>u >>v;
		u--; v--;
		link[u].push_back(v);
		link[v].push_back(u);
	}
	
	vector<int> dist(n,-1);
	vector<int> parent(n,-1);
	
	
	
	queue<int> q;
	
	dist[a] = 0;
	q.push(a);
	
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		//cout <<"take " <<v <<endl;
		for (int next : link[v])
		{
			if (dist[next] == -1)
			{
				q.push(next);
				dist[next] = dist[v] + 1;
				parent[next] = v;
				//cout <<"push " <<next <<" ( dist = " <<dist[next] <<")" <<endl;
			}
		}
	}
	
	if (dist[b] == -1)
		cout <<-1 <<endl;
	else
	{
		cout <<dist[b] <<endl;
		vector<int> path;
		int curr = b;
		while (curr != a)
		{
			path.push_back(curr);
			curr = parent[curr];
		}
		path.push_back(a);
		reverse(path.begin(),path.end());
		for (int v: path)
		{
			cout <<v+1 <<" ";
		}
		cout <<endl;
	}
	
	return 0;
}
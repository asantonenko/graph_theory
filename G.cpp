#include <iostream>

#include<vector>
#include<algorithm>
#include<cassert>
#include<queue>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

struct vertex
{
	int v;
	int dist; 
	vertex (int v, int dist): v(v), dist(dist) {}
};
bool operator<(const vertex& a, const vertex& b)
{
	return a.dist > b.dist;
}

struct edge
{
	int where;
	int weight;
	edge (int wh, int wt): where(wh), weight(wt){}
}; 

int main()
{
	int n,m;
	
	cin >>n >>m;
	
	vector < vector <edge> > link(n);

	
	int s, f;
	cin >> s >>f;
	s--;f--;
	
	for (int i = 0; i < m; i++)
	{
		int b, e, w;
		cin >>b >>e >>w;
		b--; e--;
		link[b].push_back(edge(e,w));
		link[e].push_back(edge(b,w));
	}
	
	vector<int> dist(n,-1);
	vector<int> parent(n,-1);
	
	
	
	priority_queue<vertex> q;
	
	dist[s] = 0;
	q.push(vertex(s,0));
	
	while (!q.empty())
	{
		vertex curr = q.top(); q.pop();
		if (curr.dist > dist[curr.v]) continue; 
		//cout <<"take " <<v <<endl;
		for (edge next : link[curr.v])
		{
			if (dist[next.where] == -1 || dist[next.where] > curr.dist + next.weight )
			{
				dist[next.where] = curr.dist + next.weight;
				q.push(vertex(next.where,dist[next.where]));
				parent[next.where] = curr.v;
				//cout <<"push " <<next <<" ( dist = " <<dist[next] <<")" <<endl;
			}
		}
	}
	
	if (dist[f] == -1)
		cout <<-1 <<endl;
	else
	{
		cout <<dist[f] <<endl;
		vector<int> path;
		int curr = f;
		while (curr != s)
		{
			path.push_back(curr);
			curr = parent[curr];
		}
		path.push_back(s);
		reverse(path.begin(),path.end());
		for (int v: path)
		{
			cout <<v+1 <<" ";
		}
		cout <<endl;
	}
	
	return 0;
}
#include <iostream>

#include<vector>
#include<algorithm>
#include<cassert>


using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n, m;

vector< vector<int> > lnk;

int part[100] = {0};

bool dfs (int v, int p)
{
	if (part[v]!=0)
		return (p==-1) || (part[p]!=part[v]);
	if (p!=-1)
	{
		part[v] = part[p] + 1;
		if (part[v] > 2) part[v] = 1;
	}
	else part[v] = 1;
	for (int next : lnk[v])
	{
		if (!dfs(next, v))
			return false;
	}
	return true;
}

int main()
{
	
	cin >>n >>m;
	
	lnk.resize(n);
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >>u >>v;
		u--;v--;
		lnk[u].push_back(v);
		lnk[v].push_back(u);
	}
	
	for (int i=0; i<n; i++)
		if (!dfs(i, -1))
		{
			cout <<"NO" <<endl;
			return 0;
		}
		
	cout <<"YES" <<endl;
		
	return 0;
}
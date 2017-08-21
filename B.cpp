#include <iostream>

#include<vector>
#include<algorithm>
#include<cassert>


using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n;

string lab[10];

int color[10][10] = {{WHITE}};

void dfs (int i, int j)
{
	if (i<0) //...
		return;
	if (lab[i][j]!='.')
		return;
	if (color[i][j]!=WHITE)
		return;
	color[i][j] = GRAY;//lab[i][j]='*';
	dfs(i-1,j);dfs(i+1,j);dfs(i,j-1);dfs(i,j+1);
	color[i][j] = BLACK;
}

int main()
{
	
	cin >>n;
	
	for (int i = 0; i < n; i++)
	{
		cin >>ws; getline(cin,lab[i]);
	}
	
	int r,c;
	cin >>r >>c;
	r--; c--;
	dfs ( r, c );
	
	int cnt = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		assert(color[i][j]!=GRAY);
		if (color[i][j]==BLACK)
			cnt++;
	}
	
	cout <<cnt <<endl;
	
	return 0;
}
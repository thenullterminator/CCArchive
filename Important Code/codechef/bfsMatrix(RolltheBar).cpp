#include <bits/stdc++.h>
using namespace std;
#define k 1001
int n,m;
int bfs[k][k][3];
string s[k];
queue< pair<pair<int,int>,int> >q;

bool check(int i,int j)
{
	if(i < 1 || i > n || j < 1 || j > m) return 0;
    	if(s[i][j] == '0') return 0;
    	return 1;
}

void add(int i,int j,int state,int dist)
{
	if(bfs[i][j][state]!=-1) return ;
	bfs[i][j][state]=dist;
	q.push({{i,j},state});
}


void solveBFS(int x,int y,string s[])
{

	// Initalising queue
	while(!q.empty()) q.pop();

	// initialising bfs
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			bfs[i][j][0]=-1;
			bfs[i][j][1]=-1;
			bfs[i][j][2]=-1;
		}
	}
	
	// 2-vertical
	// 1-horizontal
	// 0-sq base
	

	q.push({{x,y},0});
	bfs[x][y][0]=0;

	while(!q.empty())
	{
		int i=(q.front()).first.first,j=(q.front()).first.second,state=(q.front()).second;
		q.pop();

		int dist=bfs[i][j][state];

		if(state==0)
		{
			if(check(i-1,j) && check(i-2,j)) add(i-2,j,2,dist+1); // up state-1
			if(check(i+1,j) && check(i+2,j)) add(i+1,j,2,dist+1); // down state-1
			if(check(i,j-1) && check(i,j-2)) add(i,j-2,1,dist+1); // left state-2
			if(check(i,j+1) && check(i,j+2)) add(i,j+1,1,dist+1); // right state-2
		}
		else if(state==1)
		{
			if(check(i,j-1)) add(i,j-1,0,dist+1);  
			if(check(i,j+2)) add(i,j+2,0,dist+1); 
		
			if(check(i-1,j) && check(i-1,j+1)) add(i-1,j,1,dist+1); 
			if(check(i+1,j) && check(i+1,j+1)) add(i+1,j,1,dist+1); 
		}
		else if(state==2)
		{
			if(check(i-1,j)) add(i-1,j,0,dist+1);  
			if(check(i+2,j)) add(i+2,j,0,dist+1); 
		
			if(check(i,j+1) && check(i+1,j+1)) add(i,j+1,2,dist+1); 
			if(check(i,j-1) && check(i+1,j-1)) add(i,j-1,2,dist+1); 
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<bfs[i][j][0]<<" ";
		}
		cout<<endl;
	}
}

int main(void)
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int x,y;//n-rows and m-columns.
		cin>>n>>m;
		cin>>x>>y;


		for(int i=1;i<=n;i++) {cin>>s[i];s[i]='#'+s[i];}

		solveBFS(x,y,s);
	}
	return 0;
}

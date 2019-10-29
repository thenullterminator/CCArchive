#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b)
{
	return (a.first+a.second)>(b.first+b.second);
}


int main(void)
{
	int N,r;
	cin>>N>>r;
	vector<pair<int,int>>p,n;
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		int a,b;
		cin>>a>>b;
		
		if(b>=0) p.push_back({a,b});
		else n.push_back({a,b});
		
	}
	sort(p.begin(),p.end());
	sort(n.begin(),n.end(),cmp);
	
	int i=0;
	
	while(i<p.size())
	{
		if(p[i].first<=r)
		{
			r+=p[i].second;
			ans++;
		}
		else break;
		i++;
	}
	// Everthing is correct till here....
	
	vector<vector<int>> dp(n.size() + 1, vector<int>(r + 1, 0));
	
	
	
	dp[0][r]=ans;
	
	for(int i=0;i<n.size();i++)
	{
		for(int j=0;j<=r;j++)
		{
			if(j>=n[i].first && j+n[i].second>=0)
			{
				dp[i+1][j+n[i].second]=max(dp[i+1][j+n[i].second],dp[i][j]+1);
			}
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		}
	}
	
	int maxn=INT_MIN;
	for(int i=0;i<=r;i++) maxn=max(maxn,dp[n.size()][i]);
	cout<<maxn<<endl;
	
	return 0;
}
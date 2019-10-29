#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int n;
	cin>>n;
 
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	
	vector<pair<int,int>> dp[17];
	
	for(int i=0;i<n;i++) dp[0].push_back({v[i],0});
	
	int curlen=1;
	for(int i=1;i<17;i++)
	{
		curlen*=2;
		
		for(int j=0;j+curlen<=n;j++)
		{
			
			int cand=dp[i-1][j].second+dp[i-1][j+curlen/2].second;
			int last1=dp[i-1][j].first,last2=dp[i-1][j+curlen/2].first;
			int sum=last1+last2;
			if(sum>=10) {
				sum=sum%10;
				cand++;
			}
			
			dp[i].push_back({sum,cand});
		}
		
	}
 
 
 
 
	int q;
	cin>>q;
	
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--;r--;
		
		int deg=ceil(log(r-l+1)*1.0/log(2)*1.0);
		cout<<dp[deg][l].second<<endl;
	}
	
	return 0;
}
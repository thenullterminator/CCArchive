#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		int n;
		cin>>n;
		
		vector<int> count(n+1);
		vector<int> countone(n+1);
		
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			count[a]++;
			
			if(b) countone[a]++;
		}
		
		vector<int> types[n+1];
		
		for(int i=1;i<=n;i++)
		{
			types[count[i]].push_back(countone[i]);
		}
		
		long long ans=0,ansf=0;
		multiset<int> s;
		
		for(int i=n;i>=0;i--)
		{
			for(auto x: types[i]) s.insert(x);
			
			if(!s.empty())
			{
				int z=*s.rbegin();
				ansf+=min(z,i);
				ans+=i;
				s.erase(s.find(z));
			}
		}
		cout<<ans<<" "<<ansf<<endl;
	}
	
	return 0;
}
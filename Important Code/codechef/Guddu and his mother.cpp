#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		long long  n;
		cin>>n;
		
		vector<long long> a(n+1);
		vector<long long> prefix(n+1);
		
		for(int i=1;i<=n;i++) cin>>a[i];
		
		prefix[0]=0;
		for(int i=1;i<=n;i++) prefix[i]=a[i]^prefix[i-1];
		
		map<int,vector<int>>  m;
		
		for(int i=0;i<=n;i++) m[prefix[i]].push_back(i);
		
		
		long long  ans=0;
		for(auto i=m.begin();i!=m.end();i++)
		{
			long long n2=(i->second).size();
			if(n2>2)
			{
				
				for(long long j=0;j<n2-1;j++)
				{
					ans+=(2*j+1-n2)*((i->second)[j]);
				}
				ans+=(n2-1)*(i->second)[n2-1];
				ans-=(n2*(n2-1))/2;
			}
			else if(n2==2)
			{
				ans+=(i->second)[1]-(i->second)[0]-1;
			}
		}
		
		cout<<ans<<endl;
		
	}
	return 0;
}
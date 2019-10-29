#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int tc,z;
	cin>>tc;
	z=tc;
	for(int z=1;z<=tc;z++)
	{
		int n,k,b,t;
		cin>>n>>k>>b>>t;
		
		vector<int> x(n),s(n);
		
		for(int i=0;i<n;i++) cin>>x[i];
		for(int i=0;i<n;i++) cin>>s[i];
		
		int done=0,ans=0;
		for(int i=n-1;i>=0 && done<k ;i--)
		{
			if((s[i]*t)>=(b-x[i])) done++;
			else ans+=k-done;
		}
		
		cout<<"Case #"<<z<<": ";
		if(done<k)cout<<"IMPOSSIBLE\n";
		else cout<<ans<<"\n";
		
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int>rg(200005);

int main(void)
{
	string s,t;
	cin>>s>>t;
	
	long long ans=0;
	
	for(int i=t.size()-1;i>=0;i--)
	{
		int pos=s.size()-1;
		if(i+1<t.size()) pos=rg[i+1]-1;
		
		while(s[pos]!=t[i] && pos>=0) pos--;
		rg[i]=pos;
	}
	
	long long pos=0;
	for(int i=0;i<s.size();i++)
	{
		long long  rpos=s.size()-1;
		if(pos<t.size()) rpos=rg[pos]-1;
		ans=max(ans,rpos-i+1);
		
		if(pos<t.size() && t[pos]==s[i]) pos++;
	}
	
	cout<<ans<<endl;
	return 0;
}
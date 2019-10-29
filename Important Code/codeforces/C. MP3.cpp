#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int  n,I;
	cin>>n>>I;
	map<int ,int> m;
	
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		m[x]++;
	}
	
	int k=(8*I)/n;
	
	k=min(20,k);
	
	int K=pow(2,k);
	
	if(m.size()<=K) cout<<0<<endl;
	else
	{
		vector<int> pre;
		int sum=0;
		for(auto i =m.begin();i!=m.end();i++)
		{
			sum+=i->second;
			pre.push_back(sum);
		}
		
		int minc=INT_MAX;
		
		for(int i=0;i<=pre.size()-K;i++)
		{
			int changes=0;
			
			if(i>0)
			{
				changes+=pre[i-1];
			}
			if(i+K-1<pre.size())
			{
				changes+=pre[pre.size()-1]-pre[i+K-1];
			}
			minc=min(minc,changes);
		}
		cout<<minc<<endl;
	}
	
	return 0;
}
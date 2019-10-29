#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	
	int q;
	cin>>q;
	
	while(q--)
	{
		int n;
		cin>>n;
		set<int,greater<int>> s;
		
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			s.insert(a);
		}
		int ans=0;
		int maxel=*s.begin();
		
		if(maxel%2==0&&maxel%3==0&&maxel%5==0)
		{
			if(s.count(maxel/2)&&s.count(maxel/3)&&s.count(maxel/5))
			{
				ans=max(ans,maxel/2 + maxel/3 + maxel/5);
			}
		}
		
		vector<int> result;
		
		while(!s.empty() && result.size()<3)
		{
			auto it=s.begin();
			int c=1;
			
			for(int i:result) c=c&(i%(*it)!=0); 
			
			if(c) result.push_back(*it);
			s.erase(it);
		}
		
		ans=max(ans,accumulate(result.begin(),result.end(),0));
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}
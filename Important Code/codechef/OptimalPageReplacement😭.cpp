#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		int n,m;//n tables and m orders
		cin>>n>>m;
		int ans=0;
		
		vector<int> order(m);
		for(int i=0;i<m;i++) cin>>order[i];
		
		unordered_set <int> table;
		for(int i=0;i<m;i++) 
		{
			int od=order[i];
			// optimal page replacment algorithm starts...	
			
			//Searching if it is already present.
			if(table.find(od)!=table.end()) continue;
			
			
			
			if(table.size()<n)
			{
				table.insert(od);
				ans++;
				continue;
			}
			
			//replacement required.
			int maxd=INT_MIN,val=-1;
			for(auto it=table.begin();it!=table.end();it++)
			{
				int j;
				for(j=i+1;j<m;j++)
				{
					if((*it)==order[j])
					{
						if(maxd<j)
						{
							maxd=j;
							val=*it;
						}
						break;
					}
				}
				
				if(j==m)
				{
					val=*it;
					break;
				}
				
			}
			ans++;
			if(val==-1)
			{
				table.erase(table.begin());
				table.insert(od);
				continue;
			}
			
			table.erase(val);
			table.insert(od);
			continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}
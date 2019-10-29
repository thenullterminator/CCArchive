#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int n,k;
	cin>>n>>k;
	
	string s;
	cin>>s;
	
	
	set<string,greater<string>> vis;
	queue<string> q;
	
	vis.insert(s);
	q.push(s);
	
	while(!q.empty())
	{
		string parent=q.front();
		q.pop();
		
		for(int i=0;i<parent.size();i++)
		{
			string temp=parent;
			temp.erase(temp.begin()+i);
			
			if(vis.find(temp)==vis.end())
			{
				vis.insert(temp);
				q.push(temp);
				
				if(vis.size()>=k)
				{
					long long sum=0,count=0;
					
					for(auto it=vis.begin();it!=vis.end();it++)
					{
						sum+=(*it).size();
						count++;
						if(count==k) break;
					}
					
					cout<<k*n-sum<<endl;
					return 0;
					
				}
			}
		}
		
	}
	
	
	cout<<-1<<endl;
	
	return 0;
}
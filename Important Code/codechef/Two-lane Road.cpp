#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		int n,k,d;
		cin>>n>>k>>d;
		
		int x[n],l[n];
		
		for(int i=0;i<n;i++) cin>>x[i];
		for(int i=0;i<n;i++) cin>>l[i];
		
		int lane=3-l[0],ans=k;
		int lastSwitch=INT_MIN;
		for(int i=0;i<n;i++)
		{
			if(lane!=l[i]) continue;
			
			int bst=max(lastSwitch+d,x[i-1]+1);
			if(bst>=x[i])
			{
				ans=x[i];
				break;
			}
			lastSwitch=bst;
			lane=3-l[i];
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
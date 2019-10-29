#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		int n,c;
		cin>>n;
		
		
		vector<int> rd(n+1,0),h(n);
		for(int i=0;i<n;i++)
		{
			cin>>c;
			int l=i-c,r=i+c;
			if(l<0) l=0;
			if(r>n-1) r=n-1;
			
			rd[l]++;
			rd[r + 1]--;
		}
		for(int i=0;i<n;i++) cin>>h[i];
		
		for(int i=1;i<=n;i++) rd[i]+=rd[i-1];
		
		rd.pop_back();
		sort(rd.begin(),rd.end());
		sort(h.begin(),h.end());
		
		if(rd==h) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

// +1 and -1 values set in order to add some values in query.
#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int n;
	cin>>n;
	long long  sum=0,maxval=-1;
	
	for(int i=0;i<n;i++)
	{
		long long  x;
		cin>>x;
		sum+=x;
		maxval=max(maxval,x);
	}
	
	if(sum%2!=0) cout<<"NO"<<endl;
	else {
		
		if(sum-maxval>=maxval) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
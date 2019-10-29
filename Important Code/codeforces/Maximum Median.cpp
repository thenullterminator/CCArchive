#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long n,k;
bool check(long long x)
{
	long long moves=0;
	for(int i=n/2;i<n;i++)
	{
		if(a[i]<x) moves+=x-a[i];
		else break;
		if(moves>k) return false;
	}
	
	if(moves<=k) return true;
	return false;
}
int main(void)
{
	cin>>n>>k;
	
	for(int i=0;i<n;i++)
	{
		long long x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	long long lo=1,hi=2000000000;
	while(hi-lo>1)
	{
		long long mid=(hi+lo)>>1;
		if(check(mid))
		{
			lo=mid;
		}
		else{
			hi=mid-1;
		}
	}
	
	if(check(hi))
	cout<<hi<<endl;
	else
	cout<<lo<<endl;
	return 0;
}
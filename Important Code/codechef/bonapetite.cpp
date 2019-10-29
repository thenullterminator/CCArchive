// Code quality , c++ Structure ,Activity selection problem, greedy.
#include <bits/stdc++.h>
using  namespace std;

struct Customer{
	int sp,fp,p;
	
	Customer(int a,int b,int c)
	{
		sp=a;fp=b;p=c;
	}
};

bool comp(Customer a,Customer b)
{
	if(a.p!=b.p) return a.p<b.p;
	return a.fp<b.fp;
}

int main(void)
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		
		vector<Customer> v;
		for(int i=0;i<n;i++)
		{
			int s,f,p;
			cin>>s>>f>>p;
			Customer a(s,f,p);
			v.push_back(a);
		}
		sort(v.begin(),v.end(),comp);
		int j=0,ans=n>0;
		for(int i=0;i<n;i++)
		{
			if(v[i].p!=v[j].p) {j=i;ans++;continue; }
			if(v[i].sp>=v[j].fp) {	j=i;ans++;continue;}
		}
		cout<<ans<<endl;
	}
	return 0;
}
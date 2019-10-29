#include <bits/stdc++.h>
#define k 200010
using namespace std;

long long  tree[30][k]={0}; // tree[i] corresponds to segment tree of ith bit..
int n,q,a;

void build(){

	for(int j=0;j<30;j++)
	{
		for(int i=n-1;i>0;i--)
		{
			tree[j][i]=tree[j][i<<1]+tree[j][i<<1|1];
		}
	}
}

void update(int x,int i){

	for(int j=0;j<30;j++)
	{
		int p=i;
		for(tree[j][p+=n]=(((x&(1<<j)))?1:0);p>1;p>>=1)
		{
			tree[j][p>>1]=tree[j][p]+tree[j][p^1];
		}
	}
}

long long   query(int t,long long  l,long long r)
{
	long long sum=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1) sum+=tree[t][l++];
		if(r&1) sum+=tree[t][--r];
	}
	return sum;
}

int main(void)
{
	cin>>n>>q;

	for(int i=0;i<n;i++)
	{
		cin>>a;
		for(int j=0;j<30;j++)
		{
			if(a&(1<<j))
			{
				tree[j][i+n]=1;
			}
		}
	}

	build(); //building all segment trees..
	
	while(q--)
	{
		int t;
		cin>>t;

		if(t==1)
		{
			int x,i;
			cin>>x>>i;
			update(x,i-1);
		}
		else
		{
			string op;long long l,r;
			cin>>op>>l>>r;
			if(l==r) {cout<<0<<endl; continue;}
			l--;
			long long ans=0;
			
			for(int j=0;j<30;j++)
			{
				long long  one=query(j,l,r);
				long long  zero=(r-l)-one;
				long long  total=one+zero;
				long long  pair=0;
				if(op=="OR")
				{
					pair+=(total*(total-1))/2;
					pair-=(zero*(zero-1))/2;
				}
				else if(op=="AND")
				{
					pair+=(one*(one-1))/2;
				}
				else if(op=="XOR")
				{
					pair+=zero*one;
				}
				ans+=(1LL<<j)*pair;	
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
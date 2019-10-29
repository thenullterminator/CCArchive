#include <bits/stdc++.h>
#define k 3000010
using namespace std;

int cnt[k]={0};
int gd[k];// stores greatest divisor other than the number itself


int main(void)
{

	for(int i=0;i<k;i++)
		gd[i]=i;
	
	gd[0]=gd[1]=-1;
	
	for(int i=2;i<k;i++)
	{
		if(gd[i]==i)
		{
			for(long long j=i*1ll*i;j<k;j+=i) //smallest prime factor calculation..........
			gd[j]=min(gd[j],i);
		}
		else
		{
			gd[i]=i/gd[i]; // greatest divisor other than itself............
		}
	}
	
	vector<int> prime(k);//prime[i] stores the position of i in the prime sequence if i is prime..........
	int y=0;
	for(int i=0;i<k;i++)
	{
		if(gd[i]==i)
		prime[i]=++y;
	}
	
	
	
	cout<<gd[1630]<<endl;
	int n,x;
	cin>>n;
	
	for(int i=0;i<2*n;i++)
	{
		cin>>x;
		cnt[x]++;
	}
	
	vector<long long> result;
	
	
	for(int i=k-1;i>=0;i--)
	{
		while(cnt[i]>0)
		{
			if(gd[i]==i)
			{
				if(cnt[prime[i]]>0&&gd[prime[i]]==prime[i])
				{
					result.push_back(prime[i]);
					cnt[prime[i]]--;
				}
			}
			else
			{
				result.push_back(i);
				cnt[gd[i]]--;
			}
			
			cnt[i]--;
		}
	}
	
	for(int i=0;i<result.size();i++)
	cout<<result[i]<<" ";
	cout<<endl;
	
	return 0;
}
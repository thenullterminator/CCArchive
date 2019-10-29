#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		int n;
		cin>>n;
		
		long long dp[n+1]={0};
		long long a[n+1]={0};
		
		for(int i=1;i<=n;i++) cin>>a[i];
		dp[0]=0;
		dp[1]=a[1];
		
		for(int i=2;i<=n;i++)
		{
			dp[i]=dp[i-1]+i*a[i];
			dp[i]=max(dp[i],dp[i-2]+i*a[i-1]+a[i]*(i-1));
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}

// The first sign of a Dp question is that, either greedy fails, or its solution looks as if greedy needs loooots of conditions to pass!

// One approach of greedy for this question, which might have struck your mind, would be that “For each ii, check both its adjacent elements and swap with the one giving more contribution to the sum.”

// So lets say that you start from i=1i=1 and go till i=Ni=N. You will fail at this case of A[]=\{105,100,110,1\}A[]={105,100,110,1}. At i=2i=2 (1-based indexing), you will feel that its best to swap (100,110)(100,110). But when you Aive at i=3i=3, you see a more optimum move was possible, which we cannot use now! Hence, there comes a need to “backtrack” our previous wrong choices and correct them! This, is a very, very sure sign of dp!!

// Some other things being, there is no 11 single rule/construction which on applying to any array, would optimize the required value. Another good sign is dependency of the value on previous choices. There are multiple such hints - but lets keep that for some later day (or editorial!). the chief and the most important one which I wanted to highlight was the need to backtrack, and that of greedy failing in all forms!


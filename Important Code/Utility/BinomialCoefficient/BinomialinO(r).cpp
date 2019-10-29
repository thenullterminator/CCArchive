#include <bits/stdc++.h>
using namespace std;

unsigned long long ncr(unsigned long long n,unsigned long long r)
{
	if(r>n-r)
	r=n-r;

	unsigned long long res=1;

	for(int i=0;i<r;i++)
	{
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}






int main(void)
{
	cout<<ncr(100,1);
}

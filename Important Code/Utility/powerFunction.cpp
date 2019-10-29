#include <bits/stdc++.h>
using namespace std;
long long  power(long long  a,long long  b,long long  mod)
{
    if(b==0)
        return 1;

    long long  val=power(a,b>>1,mod);
    long long  ans=((val%mod)*(val%mod))%mod;
    if(b%2!=0)
        ans=((ans%mod)*(a%mod))%mod;

    return ans;
}

int main()
{
   printf("%ld",power(3,1,1e9+7));
    return 0;
}
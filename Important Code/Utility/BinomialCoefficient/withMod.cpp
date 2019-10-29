#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

long long fact[100100]={0};

long long  power(long long  a,long long  b)
{
     if(b==0)
        return 1;

	long long  val=power(a,b>>1);
	long long  ans=((val%M)*(val%M))%M;
	if(b%2!=0)
        ans=((ans%M)*(a%M))%M;

    return ans;
}

long long inv_mod(long long a){
	return power(a,M-2);
}

long long ncr(long long n,long long r){

	long long ans=1;
	ans=fact[n];
	ans=((ans%M)*(inv_mod(fact[r])%M))%M;
	ans=((ans%M)*(inv_mod(fact[n-r])%M))%M;
	return ans;
}

int main(void){

	fact[0]=fact[1]=1;
	for(int i=2;i<100100;i++) fact[i]=((fact[i-1]%M)*(i%M))%M;

	long long n,k;
	cin>>n>>k;
	vector<long long> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	long long sum=0;
	for(int i=0;i<k+1;i++){
		sum=((sum%M)+(ncr(n,i)%M))%M;
	}
	cout<<sum<<endl;
	return 0;
}

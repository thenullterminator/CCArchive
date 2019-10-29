#include <bits/stdc++.h>
#define  k 5000000
using namespace std;

long long n;
vector<long long> a(k),b(k),csumb(k,0),diff1(k,0),diff2(k,0);

int main(void){

	
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	csumb[0]=b[0];
	for(int i=1;i<n;i++) csumb[i]+=csumb[i-1]+b[i];
	diff1[0]=a[0]-csumb[0];diff2[n-1]=a[n-1]-csumb[n-1];
	for(int i=1;i<n;i++) diff1[i]=max(diff1[i-1],a[i]-csumb[i]);
	for(int i=n-2;i>=0;i--) diff2[i]=max(diff2[i+1],a[i]-csumb[i]);
	long long ans=LONG_LONG_MIN;
	
	for(int j=0;j<n;j++){

		ans=max(ans,a[j]);// case 1: when i=j
		if(j==0) ans=max(ans,diff2[j+1]+a[j]+csumb[n-1]);//case 3: when i>j
		else if(j==n-1) ans=max(ans,diff1[j-1]+a[j]+csumb[j-1]);// case 2: when i<=j
		else{
			ans=max(ans,diff1[j-1]+a[j]+csumb[j-1]);// case 1: when i<=j
			ans=max(ans,diff2[j+1]+a[j]+csumb[j-1]+csumb[n-1]);//case 2: when i>j
		}	
	}
	cout<<ans<<endl;

	return 0;
}
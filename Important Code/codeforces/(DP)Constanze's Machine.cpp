#include <bits/stdc++.h>
#define k 1000000007
using namespace std;
vector<long long> cache(100010,-1);

string s;
long long dp(int sp){

	if(sp>=s.size()-1) return 1;

	if(cache[sp]!=-1) return cache[sp];

	if(s[sp]=='u' && s[sp+1]=='u') return cache[sp]=(dp(sp+1)%k+dp(sp+2)%k)%k;

	if(s[sp]=='n' && s[sp+1]=='n') return cache[sp]=(dp(sp+1)%k+dp(sp+2)%k)%k;

	return cache[sp]=dp(sp+1);
}


int main(void){

	
	cin>>s;
	for(auto i:s) if(i=='w'||i=='m') {cout<<0<<endl;return 0;} 
	cout<<dp(0)<<endl;
	return 0;
}
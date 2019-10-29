#include <bits/stdc++.h>
using namespace std;
int main(void){

	int tc;
	cin>>tc;

	while(tc--){

		string s="",e="",o="",res="";
		cin>>s;

		for(auto i:s){
			if((i-'0')&1) o.push_back(i);
			else e.push_back(i);
		}

		int s1=0,s2=0;
		for(int i=0;i<s.size();i++){

			if(s1==e.size()) {res.push_back(o[s2]);s2++;continue;}
			if(s2==o.size()) {res.push_back(e[s1]);s1++;continue;}
			int d1=e[s1]-'0',d2=o[s2]-'0';
			if(d1<d2){
				res.push_back(d1+'0');
				s1++;
			}
			else{
				res.push_back(d2+'0');
				s2++;
			}
			
		}
		cout<<res<<endl;
	}
	return 0;
}
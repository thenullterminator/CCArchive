#include <bits/stdc++.h>
using namespace std;

map<char,long long> m;

long long convert(long long b,string s){
      
      long long ans=0;
      for(auto i:s) {
            if((i>='0'&& i<='9')||(i>='A' && i<='Z'))
            ans=ans*b+m[i];
            else return -1;
            if(ans>1000000000000) return -1; 
      }
      return ans;
}

int main(void){

      int cnt=10;
      for(int i=0;i<=9;i++) m['0'+i]=i;
      for(char c='A';c<='Z';c++) { m[c]=cnt;cnt++; }

      int tc;
      cin>>tc;

      while(tc--){

            int n;
            cin>>n;

            vector<long long> v[n];

            for(int i=0;i<n;i++) {

                  long long b;string s;
                  cin>>b>>s;

                  if(b!=-1) { 
                        long long dec=convert(b,s);
                        if(dec!=-1) v[i].push_back(dec);
                  }
                  else for(long long j=2;j<=36;j++) {
                        long long dec=convert(j,s);
                        if(dec!=-1) v[i].push_back(dec);
                  }
            }

            long long ans=1e18;
            for(auto i: v[0]){
                  
                  int flag=1;

                  for(int j=1;j<n;j++){

                        int flag2=0;
                        for(auto k:v[j]) if(k==i) { flag2=1;break; }  

                        if(!flag2) { flag=0; break; }
                  }

                  if(flag) ans=min(ans,i);
            }
            if(ans==1e18) cout<<-1<<endl;
            else cout<<ans<<endl;
      }
      return 0;
}
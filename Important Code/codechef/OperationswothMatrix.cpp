#include <bits/stdc++.h>
using namespace std;

int main(void){

      int tc;
      cin>>tc;

      while(tc--){

            int n,m,q;
            long long ans=0;
            cin>>n>>m>>q;
            
            vector<int> r(n+1,0),c(m+1,0);

            while(q--){
                  int a,b;
                  cin>>a>>b;

                  r[a]++;c[b]++;
            }
            long long e1=0,e2=0,o1=0,o2=0;
            for(int i=1;i<=n;i++) if(r[i]%2==0) e1++; else o1++;
            for(int i=1;i<=m;i++) if(c[i]%2==0) e2++; else o2++;

            cout<<e1*o2+e2*o1<<endl;
      }
      return 0;
}
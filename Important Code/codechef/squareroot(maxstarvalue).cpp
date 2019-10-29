#include <bits/stdc++.h>
using namespace std;
long long  freq[1000010]={0};

int main(void){

      int tc;
      cin>>tc;

      while(tc--){

            memset(freq,0,sizeof(freq));

            long long n;
            cin>>n;
            long long ans=INT_MIN;
            vector<long long > a(n);
            for(int i=0;i<n;i++) cin>>a[i];

            for(long long i=0;i<n;i++){

                  for(long long  j=1;j*j<=a[i];j++){

                        if(a[i]%j==0){

                              if(j==a[i]/j)freq[j]++;
                              else {freq[j]++;freq[a[i]/j]++;}
                        }
                  }
                  ans=max(ans,freq[a[i]]-1);
            }
            cout<<ans<<endl;
            
      }
      return 0;
}
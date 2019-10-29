#include <bits/stdc++.h>
using namespace std;

long long msb(long long n){

      if (n == 0) 
            return 0; 
  
      long long msb = 0; 
      while (n!=0) { 
            n=n/2; 
            msb++; 
      } 
      return (msb-1);
}

int main(void){

     
      int tc;
      cin>>tc;

      while(tc--){

            long long l,r;
            cin>>l>>r;
            
            if(l==r) cout<<l<<endl;
            else
            {
            	long long q=l^r;
	            long long ans=0;
	
	            long long  msbq=msb(q);
	            for(long long i=0;i<=msbq;i++) ans+=(1LL<<i);
	            
	            long long msbr=msb(r);
	           
	            for(long long i=msbq+1;i<=msbr;i++) ans+=(r&(1LL<<i));
	            
	            cout<<ans<<endl;
            	
            }

            
      }
      return 0;
}
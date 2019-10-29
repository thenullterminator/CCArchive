#include <bits/stdc++.h>
using namespace std;
long long A[11][11]={0};
long long C[11][11]={0};
long long n,k,maxv=LONG_LONG_MIN;

long long mult(long long x,long long y){
      if(y==0) return 0;
      if(x<=(k/y)) return x*y;

      return k;
}


void matmul(long long a[][11],long long b[][11],long long c[][11]){
      

     long long  temp[11][11]={0};
      for (int i=0;i<11;i++)
      {
            for (int j=0;j<11;j++)
            {
                  long long sum=0;
                  for(int m=0;m<11;m++)
                  {sum+=mult(a[i][m],b[m][j]);sum=min(sum,k);}
                 
                  temp[i][j]=sum;
            }
      }

      for (int i=0;i<11;i++)
      {
            for(int j=0;j<11;j++)
            c[i][j]=temp[i][j];
      }

}





void power(long long p,long long ans[][11]){

      for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                  if(i==j) ans[i][j]=1;
                  else ans[i][j]=0;
            }
      }

      if(p==0)
      return ;
      power(p/2,ans);
      matmul(ans,ans,ans);
       

      if(p&1)
      matmul(ans,C,ans);

}

//matrix exponentiaition completed........

int main(void){

      cin>>n>>k;
      vector<long long> a(n,0);
      
      for(int i=0;i<n;i++) {cin>>a[i];maxv=max(maxv,a[i]);}

      if(maxv>=k) { cout<<0<<endl;return 0; }

      reverse(a.begin(),a.end());
      while(a[n-1]==0) n--;
      reverse(a.begin(),a.end());

      if(n>10){

            int cnt=0;
            while(1){
                  cnt++;
                  for(int i=1;i<n;i++){
                        a[i]+=a[i-1]; // Growth is so much that 10^18 can be acheived in few iterations....
                        if(a[i]>=k) {cout<<cnt<<endl; return 0;}
                  }
            }
      }

      
     for(int i=0;i<n;i++) A[0][i]=a[i];

      for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                  if(i<=j) C[i][j]=1;
            }
      }

      long long l=1,r=k,mid;
    
      while(l<r){
            long long ans[11][11];
            memset(ans,0,sizeof(ans));
            
            mid=(l+r)/2;
            power(mid,ans);
           
            matmul(A,ans,ans);
            long long u=ans[0][n-1];
            if(u<k) l=mid+1; else r=mid;
      }
      cout<<l<<endl;
      return 0;
}
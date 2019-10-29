#include <bits/stdc++.h>
#define k 1000000007
using namespace std;
long long  A[10][10]={0};

bool prime(int n){

      if(n<=1) return false;
      for(int i=2;i<n;i++){
            if(n%i==0) return false;
      }
      return true;
}
//function to check prime number.

void matmul(long long a[][10],long long b[][10],long long c[][10])
{
    long long  temp[10][10]={0};
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            long long sum=0;
            for(int m=0;m<10;m++)
            sum=(sum%k+((a[i][m]%k)*(b[m][j]%k))%k)%k;

            temp[i][j]=sum;
        }
    }

    for (int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        c[i][j]=temp[i][j];
    }

}

void power(long long n,long long ans[][10])
{

    for(int i=0;i<10;i++) ans[i][i]=1;


    if(n==0)
    return ;
    power(n/2,ans);
   matmul(ans,ans,ans);

   if(n&1)
   matmul(ans,A,ans);

}

//matrix exponentiaition completed........

int main(void){

      for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                  if(i==0) A[i][j]=1;
                  else{
                        if(j>0 && prime(i+j)) A[i][j]=1;
                  }
            }
      }
      // Matrix A generated.....

      int tc;
      cin>>tc;

      while(tc--){

            int n;
            cin>>n;

            if(n==1) cout<<4<<endl;
            else {

                  vector<long long> f(10,0);

                  for(int i=0;i<10;i++){
                        for(int j=0;j<10;j++){
                              if(j>0 && prime(i+j)) f[i]++;
                        }
                  }

                  if(n==2) { cout<<33<<endl;}
                  else
                  {
                        long long B[10][10]={0};
                        power(n-2,B);

                        long long sum=0;
                        for(int i=0;i<10;i++){
                              for(int j=0;j<10;j++){
                                    sum=(sum%k+((B[i][j]%k)*(f[j]%k))%k)%k;
                              }
                        }
                        cout<<sum<<endl;
                  }
            }
      }

      return 0;
}
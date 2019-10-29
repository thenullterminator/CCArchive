#include <bits/stdc++.h>
#define k 1000000007
using namespace std;

long long  z[2][2]={0};


void matmul(long long a[][2],long long b[][2],long long c[][2])
{
    long long  temp[2][2]={0};
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            long long sum=0;
            for(int m=0;m<2;m++)
            sum=(sum%k+((a[i][m]%k)*(b[m][j]%k))%k)%k;

            temp[i][j]=sum;
        }
    }

    for (int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        c[i][j]=temp[i][j];
    }

}





void power(long long n,long long ans[][2])
{

    ans[0][0]=1;ans[0][1]=0;ans[1][0]=0;ans[1][1]=1;


    if(n==0)
    return ;
    power(n/2,ans);
   matmul(ans,ans,ans);

   if(n&1)
   matmul(ans,z,ans);

}

//matrix exponentiaition completed........





int main()
{

    z[0][0]=1; z[0][1]=1;z[1][0]=1;z[1][1]=0;

    int tc;
    cin>>tc;

    while(tc--)
    {
        long long n;
        cin>>n;
        if(n==1)
            cout<<"2"<<endl;

        else if(n==2)
            cout<<"3"<<endl;
        else
        {
        long long a[2][2]={0};
        long long b[2][2]={0};
        b[0][0]=1;

        power(n+1,a);

        matmul(a,b,b);


        cout<<b[0][0]<<endl;
        }
    }
    return 0;
}

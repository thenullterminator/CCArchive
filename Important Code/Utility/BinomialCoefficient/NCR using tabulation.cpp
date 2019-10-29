#include <bits/stdc++.h>
#define k 1000000007
using namespace std;
long long c[1001][1001]={0};
int main(void)
{
    //c[n][r]=ncr
    
    c[0][0]=1;
    for(int i=1;i<1001;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if((j==0)||(j==i))
            c[i][j]=1;
            else
            c[i][j]=(c[i-1][j-1]%k+c[i-1][j]%k)%k;
            
        }
    }
    
    int tc;
    cin>>tc;
    
    while(tc--)
    {
        int n,r;
        cin>>n>>r;
        if(r>n)
        cout<<0<<endl;
        else
        cout<<c[n][r]<<endl;
    }
    return 0;
}
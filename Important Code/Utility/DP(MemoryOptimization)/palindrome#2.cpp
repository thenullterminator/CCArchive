#include<bits/stdc++.h>
using namespace std;
 
int dp[3][5009];
string str;
 
int main(){
    int n;
    cin>>n>>str;
 
    // handling the empty / single characters strings case
    for(int j = 0 ; j < n ; j++)
        dp[0][j] = dp[1][j] = 0;
 
    // iterating through lengths 
    for(int len = 2 ; len <= n ; len++){
 
        // initiating the table we are going to fill
        for(int l = 0 ; l < n ; l++)
            dp[2][l] = (1<<30);
 
        // filling table as described
        for(int l = 0 ; l + len - 1 < n ; l++){
            if(str[l] == str[l + len - 1])
                dp[2][l] = dp[0][l + 1];
            else dp[2][l] = min(dp[1][l+1] , dp[1][l]) + 1;
        }
 
        // dropping the pre-previous table and shifting our tables
        swap(dp[1] , dp[0]);
        swap(dp[1] , dp[2]);
 
        // make sure to always initialize your next table before filling
        // because as you can see we are bringing a table with old values that may affect our answer
    }
    cout<<dp[1][0]<<endl;
}
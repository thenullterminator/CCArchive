#include <bits/stdc++.h>
using namespace std;
int lcs[2][6000];
int main(void){
        
        int n;
        string s;
        cin>>n>>s;

        // lcs[i][j] -> longest Common seq starting with i in s and j in r........
        string r;
        r=s;
        reverse(r.begin(),r.end());

        

        for(int i=0;i<=s.size();i++) { lcs[0][i]=lcs[1][i]=0; }

        for(int i=s.size()-1;i>=0;i--){

                for(int j=s.size()-1;j>=0;j--){
                        if(s[i]==r[j]) lcs[0][j]=1+lcs[1][j+1];
                        else lcs[0][j]=max(lcs[1][j],lcs[0][j+1]);
                }

                swap(lcs[0],lcs[1]);
        }

        cout<<s.size()-lcs[1][0]<<endl;
        return 0;
} 
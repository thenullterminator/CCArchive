#include <bits/stdc++.h>
using namespace std;

int main(void){

        int n;
        cin>>n;

        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        vector<int> l(n,1),r(n,1);

     
        for(int i=1;i<n;i++){

                if(v[i-1]<v[i]) r[i]=r[i-1]+1;
        }

        for(int i=n-2;i>=0;i--){

                if(v[i]<v[i+1]) l[i]=l[i+1]+1;
        }

        int ans=INT_MIN;

        for(int i:l) ans=max(ans,i);
        
        for(int i=2;i<n-1;i++) {
                if(v[i-1]<v[i+1]) ans=max(ans,r[i-1]+l[i+1]);
        }

        cout<<ans<<endl;
        return 0;
}
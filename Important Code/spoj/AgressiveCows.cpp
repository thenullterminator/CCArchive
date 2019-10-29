#include <bits/stdc++.h>
using namespace std;

bool predicate(vector<int> &p,int n,int c,int mind){

    int curr=p[0],cnt=1;

    for(int i=1;i<n;i++){
        if(p[i]-curr>=mind){
            cnt++;
            curr=p[i];
        }
        if(cnt>=c) return true;
    }

    return false;
}

int main(void){

    int tc;
    cin>>tc;

    while(tc--){
        int n,c;
        cin>>n>>c;

        vector<int> p(n);
        for(int i=0;i<n;i++) cin>>p[i];

        sort(p.begin(),p.end());

        int lo=1,hi=p[n-1];

        while(lo<hi){
            int mid=lo+(hi-lo+1)/2;
            if(predicate(p,n,c,mid)) lo=mid;
            else hi=mid-1;
        }
        cout<<lo<<endl;
    }
    return 0;
}
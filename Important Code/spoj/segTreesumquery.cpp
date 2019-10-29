#include <bits/stdc++.h>
#define k 100010
using namespace std;

int n;
struct node{

     long long  mxprefix;// max prefix sum.
     long long  mxsuffix;// max suffix sum.
     long long  sum; // total sum.
     long long  ans;
} tree[k];

node combine(node a,node b){

     node c;
     c.ans=max(max(a.ans,b.ans),a.mxsuffix+b.mxprefix);
     c.sum=a.sum+b.sum;
     c.mxprefix=max(a.sum+b.mxprefix,a.mxprefix);
     c.mxsuffix=max(b.sum+a.mxsuffix,b.mxsuffix);
     return c;
}

void build(){

     for(int i=n-1;i>0;i--){
          tree[i]=combine(tree[i<<1],tree[i<<1|1]);
     }
}

long long  query(int l,int r){

     node left,right;
     left.ans=left.sum=left.mxprefix=left.mxsuffix=INT_MIN; //Take special care over here.
     right.ans=right.sum=right.mxprefix=right.mxsuffix=INT_MIN;//Take special care over here.

     for(l+=n,r+=n;l<r;l>>=1,r>>=1){
          if(l&1){left=combine(left,tree[l++]);}
          if(r&1){right=combine(tree[--r],right);}
     }
     node ans=combine(left,right);
     return ans.ans;
}

int main(void){

     cin>>n;
     for(int i=0;i<n;i++){
          int x;
          cin>>x;
          tree[i+n].ans=tree[i+n].mxprefix=tree[i+n].mxsuffix=tree[i+n].sum=x;
     }
     int m;
     cin>>m;
     build();
     while(m--){
          int l,r;
          cin>>l>>r;
          l--;
          cout<<query(l,r)<<endl;
     }
     return 0;
}
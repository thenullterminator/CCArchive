#include <bits/stdc++.h>
using namespace std;
 
int n,q;
 
struct node{
     int maxf;
     int right,left;
     int fright,fleft;
};
 
node combine (node a,node b){
 
    node c;
    c.left=a.left;
    c.right=b.right;
    c.fleft=a.fleft;
    c.fright=b.fright;
    c.maxf=max(a.maxf,b.maxf);
    if(a.right==b.left) {
          c.maxf=max(c.maxf,a.fright+b.fleft);
          if(a.left==a.right) c.fleft+=b.fleft;
          if(b.left==b.right) c.fright+=a.fright;
     }
    return c;
}
 
void build( node tree[]){
 
     for(int i=n-1;i>0;i--){
 
          tree[i]=combine(tree[i<<1],tree[i<<1|1]);
     }
 
}
 
int query(node tree[],int l,int r)
{
     node left,right; 
     
     int flagl=0,flagr=0;
     for(l+=n,r+=n;l<r;l>>=1,r>>=1){
          if(l&1){ 
               if(flagl==0) {left=tree[l++];flagl++;}
               else left=combine(left,tree[l++]);
          }
          if(r&1){
               if(flagr==0) {right=tree[--r];flagr++;}
               else right=combine(tree[--r],right);
          }
     }
     node ans=combine(left,right);
     return ans.maxf;
}
int main(void)
{
     while(1)
     {
          cin>>n;
          if(n==0) break;
          cin>>q;
          node tree[2*n+10];
          for(int i=0;i<n;i++) {
               int x;
               cin>>x;
               tree[i+n].right=tree[i+n].left=x;
               tree[i+n].fleft=tree[i+n].fright=tree[i+n].maxf=1;
          }
          build(tree);
          while(q--)
          {
               int l,r;
               cin>>l>>r;
               if(l==r){cout<<1<<endl;continue;}
               l--;
               cout<<query(tree,l,r)<<endl;
          }
     }
     return 0;
}
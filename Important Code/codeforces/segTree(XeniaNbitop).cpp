#include <bits/stdc++.h>
using namespace std;
long long  n,m;
struct node{
	long long  dist;
	long long  value;
};

node combine(node a,node b){
	node c;
	c.dist=a.dist+1;
	if((c.dist)&1) c.value=(a.value)|(b.value);
	else c.value=(a.value)^(b.value);
	return c;
}

void build(node tree[]){

	for(int i=n-1;i>0;i--){
		tree[i]=combine(tree[2*i],tree[2*i+1]);
	}

}

void update(node tree[],int p, long long b){ //p-should be zero based......
	
	for(tree[p+=n].value=b;p>1;p>>=1){
		tree[p>>1]=combine(tree[p],tree[p^1]);
	}
}

int main(void){

	
	cin>>n>>m;
	n=pow(2,n);
	node tree[300010];

	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		tree[i+n].dist=0;
		tree[i+n].value=x;
	}

	
	build(tree);

	while(m--){
		int p;long long b;
		cin>>p>>b;
		update(tree,p-1,b);
		cout<<tree[1].value<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int mask= 1<<9;
int person[mask]={0};
vector<pair<int,int> > pizza[mask];
 
int main(void)
{
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		int choice=0;
		for(int j=0;j<k;j++)
		{
			int a;
			cin>>a;
			a--;
			choice|=1<<a;
		}
		person[choice]++;
	}
	
	for(int i=0;i<m;i++)
	{
		int cost,k;
		cin>>cost>>k;
		int choice=0;
		for(int j=0;j<k;j++)
		{
			int a;
			cin>>a;
			a--;
			choice|=1<<a;
		}
		pizza[choice].push_back({cost,i});
		
		sort(pizza[choice].begin(),pizza[choice].end());
		while(pizza[choice].size()>2) pizza[choice].pop_back();
	}
	
	int pleased=0,anscost=INT_MAX,ansx=0,ansy=0;
	for(int p1=0;p1<mask;p1++)
	{
		for(int p2=0;p2<mask;p2++)
		{
			int cost=0,msk=0,x=0,y=0;
			
			if(p1==p2)
			{
				if(pizza[p1].size()<2) continue;
				cost=pizza[p1][0].first+pizza[p1][1].first;
				x=pizza[p1][0].second;y=pizza[p1][1].second;
			}
			else
			{
				if(pizza[p1].size()==0||pizza[p2].size()==0) continue;
				cost=pizza[p1][0].first+pizza[p2][0].first;
				x=pizza[p1][0].second;y=pizza[p2][0].second;
			}
			
			msk=p1|p2;
			int curpleased=0;
			for(int i=0;i<mask;i++)
			{
				if((i&msk)==i) curpleased+=person[i];
			}
			
			if(curpleased>pleased||(curpleased==pleased&&cost<anscost))
			{
				pleased=curpleased;
				anscost=cost;
				ansx=x;ansy=y;
			}
		}
	}
	
	cout<<ansx+1<<" "<<ansy+1<<endl;
	return 0;
}
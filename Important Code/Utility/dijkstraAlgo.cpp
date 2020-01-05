#include <bits/stdc++.h>
using namespace std;

long long  djalgo(int s,int d,vector<pair<int,int>> graph[],int n){

        vector<long long> dis(n+1,LONG_LONG_MAX);
        vector<bool> vis(n+10,false);
        
        priority_queue< pair <long long ,int>,vector < pair<long long ,int> > , greater<pair<long long,int> > > pq;
        pq.push({0,s});
        dis[s]=0;

        while(!pq.empty()){
                int u=pq.top().second;
                vis[u]=true;
                pq.pop();

                if(u==d) return dis[d];

                for(auto i:graph[u]){

                        int v=i.first;
                        long long  w=i.second;
                        
                        if(vis[v]==false && (dis[u]+w)<dis[v]){
                                dis[v]=dis[u]+w;
                                pq.push({dis[v],v});
                        }
                }
        }
        
        return dis[d];
}
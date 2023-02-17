#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[n];
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    int src;cin>>src;
    priority_queue <pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int>shortest_dist(n,INT_MAX);
    shortest_dist[src] = 0;
    q.push({0,src});
    while(!q.empty()){
        int distance = q.top().first, node = q.top().second;
        q.pop();
        for(auto i:g[node]){
            int dist = distance+i.second;
            if(dist < shortest_dist[i.first]){
                shortest_dist[i.first] = dist;
                q.push({dist,i.first});
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<src<<" --> "<<i<<" ---- "<<shortest_dist[i]<<endl;
    }
}
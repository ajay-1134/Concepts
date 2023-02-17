#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[n];
    for(int i=0; i<m; i++){
        int u,v,wt;cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    int src,destination;cin>>src>>destination;
    vector<int>shortest_distance(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
    shortest_distance[src] = 0;
    vector<int>parent(n,-1);
    q.push({0,src});
    while(!q.empty()){
        int min_d = q.top().first, node = q.top().second;
        q.pop();
        for(auto i:g[node]){
            if(min_d+i.second < shortest_distance[i.first]){
                shortest_distance[i.first] = min_d+i.second;
                parent[i.first] = node;
                q.push({min_d+i.second,i.first});
            }
        }
    }
    vector<int>path;
    int curr = destination;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(),path.end());
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<endl;
    }

}
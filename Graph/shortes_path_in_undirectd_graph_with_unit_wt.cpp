#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<int>g[], int n, int src){
    vector<int>dist(n,INT_MAX);
    int visited[n] = {0};

    queue<pair<int,int>>q;
    q.push({src,0});
    dist[src] = 0;
    while(!q.empty()){
        pair<int,int>p = q.front();
        int node = p.first, distance = p.second;
        q.pop();
        for(auto i:g[node]){
            if(!visited[i]){
                visited[i] = 1;
                dist[i] = min(dist[i], distance+1);
                q.push({i,distance+1});
            }
        }
    }
    for(int i=0; i<n; i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    return dist;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    for(int i=0; i<m; i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int src;cin>>src;

    vector<int>ans = shortestPath(g,n,src);
    for(int i=0; i<n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
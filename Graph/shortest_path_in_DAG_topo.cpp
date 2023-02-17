#include<bits/stdc++.h>
using namespace std;

void dfs_topo(int node, vector<pair<int,int>>g[], vector<int>&visited, stack<int>&st){
    visited[node] = 1;
    for(auto i:g[node]){
        if(!visited[i.first]){
            dfs_topo(i.first,g,visited,st);
        }
    }
    st.push(node);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[n];
    for(int i=0; i<m; i++){
        int u,v,wt;cin>>u>>v>>wt;
        g[u].push_back({v,wt});
    }
    int sr,dest;cin>>sr>>dest;
    vector<int>visited(n,0);
    stack<int>st;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs_topo(i,g,visited,st);
        }
    }

    vector<int>dist(n,1e9);

    dist[sr] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto i:g[node]){
            int v = i.first, wt = i.second;
            if(dist[node]+wt < dist[v]){
                dist[v] = dist[node] + wt;
            } 
        }

    }
    for(int i=0; i<n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    // cout<<dist[dest]<<endl;


}
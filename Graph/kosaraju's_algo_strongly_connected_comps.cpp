#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>g[], vector<int>&vis, stack<int>&st){
    vis[node] = 1;
    for(auto i:g[node]){
        if(!vis[i]){
            dfs(i,g,vis,st);
        }
    }
    st.push(node);
}

void dfs3(int node, vector<int>gT[], vector<int>&vis2){
    vis2[node] = 1;
    for(auto i:gT[node]){
        if(!vis2[i]){
            dfs3(i,gT,vis2);
        }
    }
}

int kosaraju(int V, vector<int> g[])
{
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0; i<V; i++){
        if(!vis[i]) dfs(i,g,vis,st);
    }
    
    vector<int>gT[V];
    for(int i=0; i<V; i++){
        for(auto j:g[i]){
            gT[j].push_back(i);
        }
    }
    
    int cnt = 0;
    vector<int>vis2(V,0);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis2[node]){
            dfs3(node,gT,vis2);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    for(int i=0; i<m; i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }
    cout<<kosaraju(n,g)<<endl;
}
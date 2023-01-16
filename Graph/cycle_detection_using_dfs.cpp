#include<bits/stdc++.h>
using namespace std;

bool ans;

void dfs(vector<int>g[], int node, int parent, vector<bool>&visited){
    visited[node] = true;
    for(auto i:g[node]){
        if(visited[i] == true && i!=parent){
            ans = true;
        }
        else if(visited[i] == false){
            dfs(g,i,node,visited);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i=0; i<m; i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool>visited(n+1);

    for(int i=1; i<=n; i++){
        if(visited[i] == false){
            dfs(g,i,-1,visited);
        }
    }
    cout<<ans<<endl;

}
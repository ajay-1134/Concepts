#include<bits/stdc++.h>
using namespace std;

int timer = 1;
void dfs(int node, int parent, vector<int>&vis, vector<int>g[], int tin[], int low[], vector<vector<int>>&bridges){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto i:g[node]){
        if(i == parent) continue;
        if(!vis[i]){
            dfs(i,node,vis,g,tin,low,bridges);
            low[node] = min(low[node],low[i]);
            if(low[i] > tin[node]){
                bridges.push_back({i,node});
            }
        }
        else{
            low[node] = min(low[node],low[i]);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    for(int i=0; i<n; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>vis(n,0);
    int tin[n];
    int low[n];
    vector<vector<int>>bridges;
    dfs(0,-1,vis,g,tin,low,bridges);
    for(auto i:bridges){
        cout<<i[0]<<" "<<i[1]<<endl;
    }

}
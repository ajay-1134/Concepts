#include<bits/stdc++.h>
using namespace std;



bool detect_cycle_dfs(int node, vector<int>g[], vector<int>&visited, vector<int>&path_visited, vector<int>&check){
    visited[node] = 1;
    path_visited[node] = 1;
    check[node] = 0;
    for(auto i:g[node]){
        if(visited[i] == 0){
            if( detect_cycle_dfs(i,g,visited,path_visited,check) == true) {
                check[node] = 0;
                return true;
            }
        }
        else if(path_visited[i] == 1){
            check[node] = 0;
            return true;
        }
    }
    check[node] = 1;
    path_visited[node] = 0;
    return false;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n];

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    
    vector<int>visited(n,0);
    vector<int>path_visited(n,0);
    vector<int>check(n,0);
    for(int i=0; i<n; i++){
        if(visited[i] == 0){
            detect_cycle_dfs(i,g,visited,path_visited,check);
        }
    }

    for(int i=0; i<n; i++){
        if(check[i] == 1) cout<<i<<" ";
    }
}
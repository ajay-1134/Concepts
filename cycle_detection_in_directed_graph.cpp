#include<bits/stdc++.h>
using namespace std;

bool detect_cycle_dfs(int node, vector<int>g[], vector<int>&visited, vector<int>&path_visited){
    visited[node] = 1;
    path_visited[node] = 1;
    for(auto i:g[node]){
        if(visited[i] == 0){
            if( detect_cycle_dfs(i,g,visited,path_visited) == true) return true;
        }
        else if(visited[i] == 1 && path_visited[i] == 1){
            return true;
        }
    }
    path_visited[node] = 0;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>g[n+1];
    for(int i=0; i<m; i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }
    vector<int>visited(n+1,0),path_visited(n+1,0);
    int flag = 0;
    for(int i=1; i<=n; i++){
        if(visited[i] == 0 && detect_cycle_dfs(i,g,visited,path_visited) == true){
            flag = 1;
            cout<<"Cycle detected"<<endl;
            break;
        }
    }
    if(flag == 0) cout<<"There is no cycle in the graph"<<endl;
    
}
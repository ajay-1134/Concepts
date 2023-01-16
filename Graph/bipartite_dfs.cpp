#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>g[], vector<int>&visited, int color){
    visited[node] = color;
    int new_color = 1;
    if(color == 1) new_color = 0;
    for(auto i:g[node]){
        if(visited[i] != -1 && visited[i] == color){
            return false;
        }
        else if(visited[i] == -1){
            if(dfs(i,g,visited,new_color) == false) return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    vector<int>visited(n+1,-1);

    int flag = 0;
    for(int i=1; i<=n; i++){
        if(visited[i] == -1){
            bool bi = dfs(i,g,visited,0);
            if(bi == false){
                flag = 1;
                cout<<"Not bipartite"<<endl;
                break;
            }
        }
    }
    if(flag == 0) cout<<"Bipartite"<<endl;
}
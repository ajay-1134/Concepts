#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<int>g[], vector<int>&visited, int node){
    bool ans = true;
    queue<pair<int,int>>q;
    visited[node] = 0;
    q.push({node,0});
    while(!q.empty()){
        pair<int,int>p = q.front(); node = p.first;int color = p.second;
        q.pop();
        for(auto i:g[node]){
            if(visited[i] != -1 && visited[i] == color){
                return false;
            }
            else if(visited[i] == -1){
                int newcol;
                if(color == 0){ visited[i] = 1; newcol = 1;}
                else if(color == 1){visited[i] = 0; newcol = 0;}
                q.push({i,newcol});
            }
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
            bool bi = bfs(g,visited,i);
            if(bi == false){
                flag = 1;
                cout<<"Not bipartite"<<endl;
                break;
            }
        }
    }
    if(flag == 0) cout<<"Bipartite"<<endl;
}
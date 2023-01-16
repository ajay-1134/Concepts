#include<bits/stdc++.h>
using namespace std;

bool bfs(int sr, vector<int>g[], int n, vector<bool>&visited){
    queue<pair<int,int>>q;
    q.push({sr,-1});
    visited[sr] = true;
    while(!q.empty()){
        pair<int,int>p = q.front();
        int node = p.first, parent = p.second;
        q.pop();
        for(auto i:g[node]){
            if(visited[i] == true && i != parent){
                return true;
            }
            else if(visited[i] == false){
                visited[i] = true;
                q.push({i,node});
            }
        }
    }
    return false;
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
    cout<<bfs(1,g,n,visited)<<endl;

}
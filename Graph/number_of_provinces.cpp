#include<bits/stdc++.h>
using namespace std;

vector<int>g[1000];
bool visited[1000];

void dfs(int node){
    visited[node] = true;
    cout<<node<<" - ";
    for(auto i:g[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    cout<<endl<<cnt<<endl;
}
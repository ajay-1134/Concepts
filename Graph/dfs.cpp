#include<bits/stdc++.h>
using namespace std;

bool visited[100];

void dfs(int node, vector<int>arr[], int n){
    visited[node] = true;
    cout<<node<<" - ";
    for(auto i : arr[node]){
        if(!visited[i]){
            dfs(i,arr,n);
        }
        
    }

}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1,arr,n);

}
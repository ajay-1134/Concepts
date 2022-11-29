#include<bits/stdc++.h>
using namespace std;

bool visited[100];

void bfs(vector<int>arr[], int n, int i){
    queue<int>q;
    visited[i] = true;
    q.push(i);
    while(!q.empty()){
        int fro = q.front();
        q.pop();
        cout<<fro<<" - ";
        for(auto j:arr[fro]){
            if(!visited[j]){
                visited[j] = true;
                q.push(j);
            }
        }
    }
    return;
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
    bfs(arr,n,1);
}
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>g[], int visited[],stack<int>&st){
    visited[node] = 1;
    for(auto i:g[node]){
        if(visited[i] == 0){
            dfs(i,g,visited,st);
        }
    }
    st.push(node);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    for(int i=0; i<m; i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }
    int visited[n] = {0};
    stack<int>st;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i,g,visited,st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        int var = st.top();
        st.pop();
        ans.push_back(var);
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    // return ans;


}
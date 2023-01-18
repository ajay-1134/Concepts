#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int>g[], vector<int>&visited, vector<int>&indegree, int n){
    vector<int>ans;
    queue<int>q;
    for(int i=0; i<n; i++){
        if(visited[i] == 0 && indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto i:g[node]){
            indegree[i]--;
            if(visited[i] == 0 && indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    vector<int>indegree(n,0); 
    for(int i=0; i<m; i++){
        int u,v;cin>>u>>v;
        indegree[v]++;
        g[u].push_back(v);
    }
    vector<int>visited(n,0);
    vector<int>ans  = bfs(g,visited,indegree,n);
    for(auto i:ans){
        cout<<i<<" ";
    }

}
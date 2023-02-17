#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int>g[], int n, vector<int>&indegree){
    vector<int>ans;
    queue<int>q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto i:g[node]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    vector<int>indegree(n,0);
    for(int i=0; i<m; i++){
        int u,v;cin>>u>>v;
        g[v].push_back(u);
        indegree[u]++;
    }
    // cout<<"Ajay"<<endl;
    vector<int>safenodes = bfs(g,n,indegree);
    for(auto i:safenodes){
        cout<<i<<" ";
    }
    cout<<endl;
}
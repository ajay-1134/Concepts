#include<bits/stdc++.h>
using namespace std;

vector<int>sorted;
bool bfs(vector<int>g[], int n, vector<int>&indegree, vector<int>&visited){
    queue<int>q;
    for(int i=0; i<n; i++){
        if(visited[i] == 0 && indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        sorted.push_back(node);
        for(auto i:g[node]){
            indegree[i]--;
            if(visited[i] == 0 && indegree[i] == 0){
                q.push(i);
            }
        }
    }
    if(sorted.size() == n) return true;
    return false;
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    vector<int>indegree(n,0);
    for(int i=0; i<m; i++){
        int v,u;cin>>v>>u;
        g[u].push_back(v);
        indegree[v]++;
    }
    vector<int>visited(n,0);
    if(bfs(g,n,indegree,visited) == true){
        for(auto i:sorted){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else cout<<"Can't be scheduled"<<endl;


}
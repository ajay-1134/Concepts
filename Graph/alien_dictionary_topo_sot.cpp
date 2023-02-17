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
    int n,k;
    cin>>n>>k;
    string arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>g[k];
    vector<int>indegree(k,0);
    for(int i=0; i<n-1; i++){
        int small_size = min(arr[i].size(),arr[i+1].size());
        for(int j=0; j<small_size; j++){
            if(arr[i][j] != arr[i+1][j]){
                g[arr[i][j]-'a'].push_back(arr[i+1][j]-'a');
                indegree[arr[i+1][j]-'a']++;
                break;
            }
        }
    }
    vector<int>visited(k,0);
    vector<int>v = bfs(g,visited,indegree,k);
    string ans = "";
    for(auto i:v){
        ans += ('a'+i);
    }
    cout<<ans<<endl;

}
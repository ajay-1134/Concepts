#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>mst(vector<pair<int,int>>g[], int n){
    vector<pair<int,int>>ans;
    int sum = 0;
    vector<int>vis(n,0);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    q.push({0,{0,-1}});
    while(!q.empty()){
        int wt = q.top().first, node = q.top().second.first, parent = q.top().second.second;
        q.pop();
        if(vis[node] == 0){
            vis[node] = 1;
            if(parent!=-1){
                ans.push_back({parent,node});
                sum += wt;
            }
        }
        for(auto i:g[node]){
            if(!vis[i.first]){
                q.push({i.second,{i.first,node}});
            }
        }
    }
    ans.push_back({-1,sum});
    return ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[n];
    for(int i=0; i<n; i++){
        int u,v,wt;cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    int mst_sum = 0;
    vector<pair<int,int>>ans = mst(g,n);
    cout<<"Weight of MST is equal to: "<<ans[n-1].second<<endl;
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }

}
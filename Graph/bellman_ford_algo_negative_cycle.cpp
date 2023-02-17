#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    int n = V;
    vector<int>dist(n,1e8);
    dist[S] = 0;
    for(int i=0; i<n-1; i++){
        for(auto i:edges){
            if(dist[i[0]] != 1e8 && dist[i[0]]+i[2] < dist[i[1]]){
                dist[i[1]] = dist[i[0]] + i[2];
            }
        }
    }
    for(auto i:edges){
        if(dist[i[0]] != 1e8 && dist[i[0]]+i[2] < dist[i[1]]){
            return {-1};
        }
    }
    return dist;
}

int main(){
    int n,m;
    cin>>n>>m;
    int src;cin>>src;
    vector<vector<int>>edges;
    for(int i=0; i<m; i++){
        int u,v,dis;
        cin>>u>>v>>dis;
        vector<int>temp = {u,v,dis};
        edges.push_back(temp);
    }
    vector<int>ans = bellman_ford(n,edges,src);
    for(auto i:ans){
        cout<<i<<" ";
    }

}
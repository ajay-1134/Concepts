#include<bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<pair<int,int>>g[], int src, int dst, int K)  {
    vector<int>cheapest(n,INT_MAX);
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}});
    while(!q.empty()){
        int stops = q.front().first, node = q.front().second.first, price = q.front().second.second;
        if(stops == K+1) break;
        q.pop();
        for(auto i:g[node]){
            int temp_price = price+i.second;
            if(temp_price < cheapest[i.first]){
                cheapest[i.first] = temp_price;
            }
            q.push({stops+1,{i.first,cheapest[i.first]}});
        }
    }
    if(cheapest[dst] == INT_MAX) return -1;
    return cheapest[dst];
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0; i<m; i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }
    int src,dest,k;
    cin>>src>>dest>>k;
    cout<<CheapestFLight(n,adj,src,dest,k)<<endl;
}
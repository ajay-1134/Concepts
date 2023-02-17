#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[n];
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    int src;cin>>src;
    set<pair<int,int>>st;
    set<pair<int,int>> :: iterator it = st.begin();
    vector<int>shortest_dist(n,INT_MAX);
    shortest_dist[src] = 0;
    st.insert({0,src});
    while(!st.empty()){
        pair<int,int>p = *st.begin();
        int distance = p.first, node = p.second;
        st.erase(st.begin());
        for(auto i:g[node]){
            int dist = distance+i.second;
            if(dist < shortest_dist[i.first]){
                if(shortest_dist[i.first] != INT_MAX){
                    st.erase({shortest_dist[i.first],i.first});
                }
                shortest_dist[i.first] = dist;
                st.insert({dist,i.first});
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<src<<" --> "<<i<<" ---- "<<shortest_dist[i]<<endl;
    }
}
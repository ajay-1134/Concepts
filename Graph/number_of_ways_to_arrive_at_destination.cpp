#include<bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<pair<int,int>>g[], int src, int dest) {
    vector<pair<int,int>>min_time(n,{INT_MAX,0});
    min_time[src] = {0,1};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,src});
    while(!q.empty()){
        int time = q.top().first, node = q.top().second;
        q.pop();
        if(node == dest) continue;
        for(auto i:g[node]){
            if(time+i.second < min_time[i.first].first){
                min_time[i.first].first = time+i.second;
                min_time[i.first].second = 1;
                q.push({time+i.second,i.first});
            }
            else if(time+i.second == min_time[i.first].first){
                min_time[i.first].second+=1;
                q.push({time+i.second,i.first});
            }
        }
    }

    return min_time[dest].second;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[n];
    for(int i=0; i<n; i++){
        int u,v,time;
        cin>>u>>v>>time;
        g[u].push_back({v,time});
        g[v].push_back({u,time});
    }
    int src = 0, dest = n-1;
    cout<<countPaths(n,g,src,dest)<<endl;
}
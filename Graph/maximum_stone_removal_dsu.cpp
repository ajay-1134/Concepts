#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        size.resize(n+1,1);
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] <= size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] +=(size[ulp_u]);
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += (size[ulp_v]);
        }
    }

};


int maxRemove(vector<vector<int>>& stones, int n) {
    int mxrow = 0, mxcol = 0;
    for(int i=0; i<n; i++){
        mxrow = max(mxrow, stones[i][0]);
        mxcol = max(mxcol, stones[i][1]);
    }
    int x = mxrow+mxcol+2;
    DisjointSet ds(x+1);
    map<int,int>mp;
    for(auto i:stones){
        ds.unionByRank(i[0], i[1]+mxrow+1);
        mp[i[0]] = 1;
        mp[i[1]+mxrow+1] = 1;
    }
    int cc = 0;
    for(auto i:mp){
        if(ds.parent[i.first] == i.first) cc++;
    }
    return n - cc;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>stones;
    for(int i=0; i<n; i++){
        int x,y;cin>>x>>y;
        stones.push_back({x,y});
    }
    cout<<maxRemove(stones,n)<<endl;
}
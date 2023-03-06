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

int main(){
    int n;
    cin>>n;
    DisjointSet ds(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int var; cin>>var;
            if(var == 1){
                ds.unionByRank(i,j);
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(ds.parent[i] == i){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
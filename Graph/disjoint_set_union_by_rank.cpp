#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
public:
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
    DisjointSet ds(7);
    /*ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    //if 3 and 7 belonging to same parent or not
    if(ds.findParent(3) == ds.findParent(7)){
        cout<<"Belonging to same component"<<endl;
    }
    else cout<<"Belonging to different component"<<endl;

    ds.unionByRank(3,7);
    if(ds.findParent(3) == ds.findParent(7)){
        cout<<"Belonging to same component"<<endl;
    }
    else cout<<"Belonging to different component"<<endl;*/

    //size
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    //if 3 and 7 belonging to same parent or not
    if(ds.findParent(3) == ds.findParent(7)){
        cout<<"Belonging to same component"<<endl;
    }
    else cout<<"Belonging to different component"<<endl;

    ds.unionBySize(3,7);
    if(ds.findParent(3) == ds.findParent(7)){
        cout<<"Belonging to same component"<<endl;
    }
    else cout<<"Belonging to different component"<<endl;
    return 0;
}
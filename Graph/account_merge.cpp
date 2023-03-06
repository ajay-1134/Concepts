#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int>rank,size,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
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

        if(ulp_u == ulp_v){
            return;
        }

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

    }
    
    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] >= size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]++;
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]++;
        }
    }
    
};

int main(){
    int n;
    cin>>n;
    DisjointSet ds(n);
    vector<vector<string>>ac;
    for(int i=0; i<n; i++){
        int m; cin>>m;
        vector<string>temp(m);
        for(int j=0; j<m; j++){
            cin>>temp[j];
        }
        ac.push_back(temp);
    }
    // for(auto i:ac){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    map<int,vector<string>>mp2;
    map<string,int>mp;
    for(int i=0; i<n; i++){
        int m = ac[i].size();
        for(int j=1; j<m; j++){
            if(mp.find(ac[i][j]) != mp.end()){
                ds.unionByRank(i,mp[ac[i][j]]);
            }
            else{
                mp[ac[i][j]] = i;
            }
        }
    }

    for(auto i:mp){
        mp2[ds.findParent(i.second)].push_back(i.first);
    }
    for(auto i:mp2){
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}
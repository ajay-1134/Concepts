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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    DisjointSet ds(n*m);
    vector<vector<int>>mat(n,vector<int>(m,0));
    int k = operators.size();
    vector<int>ans;
    int cnt = 0;
    for(int i=0; i<k; i++){
        int r = operators[i][0];
        int c = operators[i][1];
        // if(mat[r][c] == 1){
        //     ans.push_back(cnt);
        //     continue;
        // }
        mat[r][c] = 1;
        cnt++;
        int arr1[] = {1,-1,0,0};
        int arr2[] = {0,0,1,-1};
        for(int i=0; i<4; i++){
            int nr = r + arr1[i];
            int nc = c + arr2[i];
            
            if(nr>=0 && nr<n && nc >= 0 && nc < m && mat[nr][nc] == 1 && ds.findParent(r*m+c) != ds.findParent(nr*m+nc)){
                cnt--;
                ds.unionByRank(r*m+c, nr*m+nc);
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>operators;
    for(int i=0; i<k; i++){
        int r,c;cin>>r>>c;
        operators.push_back({r,c});
    }
    vector<int>ans = numOfIslands(n,m,operators);
    for(auto i:ans){
        cout<<i<<" ";
    }
}
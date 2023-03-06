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

int MaxConnection(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    DisjointSet ds(n*m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int r = i, c = j;
            if(grid[i][j] == 1){
                int arr1[] = {1,-1,0,0};
                int arr2[] = {0,0,1,-1};
                for(int id=0; id<4; id++){
                    int nr = i+arr1[id];
                    int nc = j+arr2[id];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                        ds.unionBySize(r*m+c,nr*m+nc);
                    }
                }
            }
        }
    }
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int r = i, c = j;
            set<int>st;
            if(grid[i][j] == 0){
                int arr1[] = {1,-1,0,0};
                int arr2[] = {0,0,1,-1};
                for(int id=0; id<4; id++){
                    int nr = i+arr1[id];
                    int nc = j+arr2[id];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                        st.insert(ds.findParent(nr*m+nc));
                    }
                }
                int sz = 0;
                for(auto it:st){
                    sz += ds.size[it];
                }
                mx = max(mx,sz+1);
            }
            
        }
    }
    for(int i=0; i<n*m; i++){
        mx = max(mx,ds.size[ds.findParent(i)]);
    }
    return mx;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }

    cout<<MaxConnection(grid)<<endl;

}
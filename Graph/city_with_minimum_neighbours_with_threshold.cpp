#include<bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
    vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
    for(int i=0; i<n; i++){
        mat[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        mat[u][v] = wt;
        mat[v][u] = wt;
    }
    for(int via=0; via<n; via++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == via || j == via || i == j){
                    continue;
                }
                else{
                    if(mat[i][via] == INT_MAX || mat[via][j] == INT_MAX){
                        continue;
                    }
                    if(mat[i][via] + mat[via][j] < mat[i][j]){
                        mat[i][j] = mat[i][via] + mat[via][j];
                    }
                }
            }
        }
    }
    vector<int>reachable(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j && mat[i][j] <= distanceThreshold){
                reachable[i]++;
            }
        }
    }
    int mn = INT_MAX;
    for(int i=0; i<n; i++){
        mn = min(mn,reachable[i]);
    }
    for(int i=n-1; i>=0; i--){
        if(reachable[i] == mn){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0; i<m; i++){
        int u,v,wt;cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    int threshold;cin>>threshold;
    cout<<findCity(n,m,edges,threshold)<<endl;

}
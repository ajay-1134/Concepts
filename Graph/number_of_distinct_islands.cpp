#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>mat, vector<vector<bool>>&visited, int n, int m, int r, int c, vector<pair<int,int>>&vp, int r_base, int c_base){
    visited[r][c] = true;
    vp.push_back({r-r_base,c-c_base});
    int arr1[] = {1,-1,0,0}, arr2[] = {0,0,1,-1};
    for(int i=0; i<4; i++){
        int nr = r+arr1[i], nc = c+arr2[i];
        if(nr>=0 && nr<n && nc >=0 && nc < m && mat[nr][nc] == 1 && visited[nr][nc] == false){
            visited[nr][nc] = true;
            vp.push_back({nr-r_base,nc-c_base});
            dfs(mat,visited,n,m,nr,nc,vp,r_base,c_base);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>mat;
    for(int i=0; i<n; i++){
        vector<int>temp;
        for(int j=0; j<m; j++){
            int var;cin>>var;
            temp.push_back(var);
        }
        mat.push_back(temp);
    }

    vector<vector<bool>>visited(n,vector<bool>(m,false));
    set<vector<pair<int,int>>>st;
    int cnt = 0;    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j] == false && mat[i][j] == 1){
                vector<pair<int,int>>vp;
                dfs(mat,visited,n,m,i,j,vp,i,j);
                st.insert(vp);
            }
        }
    }
    cout<<st.size()<<endl;

}
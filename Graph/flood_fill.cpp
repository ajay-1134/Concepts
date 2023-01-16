#include<bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, vector<vector<bool>>&visited, vector<vector<int>>&mat, int n, int m, int newcolor, int oldcolor){
    visited[sr][sc] = true;
    mat[sr][sc] = newcolor;
    if(sr+1 < n && mat[sr+1][sc] == oldcolor && visited[sr+1][sc] == false){
        dfs(sr+1,sc,visited,mat,n,m,newcolor,oldcolor);
    }
    if(sr-1 >= 0 && mat[sr-1][sc] == oldcolor && visited[sr-1][sc] == false){
        dfs(sr-1,sc,visited,mat,n,m,newcolor,oldcolor);
    }
    if(sc+1 < n && mat[sr][sc+1] == oldcolor && visited[sr][sc+1] == false){
        dfs(sr,sc+1,visited,mat,n,m,newcolor,oldcolor);
    }
    if(sc-1 < n && mat[sr][sc-1] == oldcolor && visited[sr][sc-1] == false){
        dfs(sr,sc-1,visited,mat,n,m,newcolor,oldcolor);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat;
    for(int i=0; i<n; i++){
        vector<int>temp;
        for(int j=0; j<m; j++){
            int var; cin>>var;
            temp.push_back(var);
        }
        mat.push_back(temp);
    }
    int sr,sc;
    cin>>sr>>sc;
    int newcolor;
    cin>>newcolor;

    vector<vector<bool>>visited;
    for(int i=0; i<n; i++){
        vector<bool>temp;
        for(int j=0; j<m; j++){
            temp.push_back(false);
        }
        visited.push_back(temp);
    }
    int oldcolor = mat[sr][sc];
    dfs(sr,sc,visited,mat,n,m,newcolor, oldcolor);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
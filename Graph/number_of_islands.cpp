#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>mat, int r, int c, vector<vector<bool>>&visited, int n, int m){
    visited[r][c] = true;
    int arr1[] = {-1,0,1};
    int arr2[] = {-1,0,1};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(r+arr1[i] >= 0 && c+arr2[j] >= 0 && r+arr1[i]<n && c+arr2[j] < m && mat[r+arr1[i]][c+arr2[j]] == 1 && visited[r+arr1[i]][c+arr2[j]]== false){
                dfs(mat,r+arr1[i],c+arr2[j],visited,n,m);
            }
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat;
    for(int i=0; i<n; i++){
        vector<int>temp;
        for(int j=0;j <m; j++){
            int var;cin>>var;
            temp.push_back(var);
        }
        mat.push_back(temp);
    }
    vector<vector<bool>>visited(n,vector<bool>(m,false));

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1 && visited[i][j] == false){
                cnt++;
                dfs(mat,i,j,visited,n,m);
            }
        }
    }
    cout<<cnt<<endl;
    
   


}
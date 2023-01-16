#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bfs(vector<vector<int>>mat, vector<vector<bool>>&visited, int n, int m){
    vector<vector<int>>ans;
    for(int i=0; i<n; i++){
        vector<int>temp;
        for(int j=0; j<m; j++){
            temp.push_back(0);
        }
        ans.push_back(temp);
    }
    queue<pair<pair<int,int>,int>>q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1){
                ans[i][j] = 0;
                q.push({{i,j},0});
            }
        }
    }

    while(!q.empty()){
        pair<pair<int,int>,int>p = q.front();
        int r = p.first.first,c = p.first.second,dist = p.second;
        q.pop();
        if(r+1<n && visited[r+1][c] == false && mat[r+1][c] == 0){
            visited[r+1][c] = true;
            ans[r+1][c] = dist+1;
            q.push({{r+1,c},dist+1});
        }
        if(r-1>=0 && visited[r-1][c] == false && mat[r-1][c] == 0){
            visited[r-1][c] = true;
            ans[r-1][c] = dist+1;
            q.push({{r-1,c},dist+1});
        }
        if(c+1<m && visited[r][c+1] == false && mat[r][c+1] == 0){
            visited[r][c+1] = true;
            ans[r][c+1] = dist+1;
            q.push({{r,c+1},dist+1});
        }
        if(c-1>=0 && visited[r][c-1] == false && mat[r][c-1] == 0){
            visited[r][c-1] = true;
            ans[r][c-1] = dist+1;
            q.push({{r,c-1},dist+1});
        }
    }
    return ans;
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
    vector<vector<bool>>visited;
    for(int i=0; i<n; i++){
        vector<bool>temp;
        for(int j=0; j<m; j++){
            temp.push_back(false);
        }
        visited.push_back(temp);
    }
    vector<vector<int>>res = bfs(mat,visited,n,m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}
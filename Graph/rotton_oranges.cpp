#include<bits/stdc++.h>
using namespace std;

int ans = 0;

void bfs(vector<vector<int>>&mat, vector<vector<bool>>&visited, int n, int m){
    
    queue<pair<int,int>>q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 2){
                visited[i][j] = true;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        int flag = 0;
        int sz = q.size();
        for(int i=0; i<sz; i++){
            pair<int,int>p = q.front();
            q.pop();
            int r = p.first,c = p.second;
            if(r+1 < n && mat[r+1][c] == 1 && visited[r+1][c] == false){
                flag = 1;
                visited[r+1][c] = true;
                mat[r+1][c] = 2;
                q.push({r+1,c});
            }
            if(r-1 >= 0 && mat[r-1][c] == 1 && visited[r-1][c] == false){
                flag = 1;
                visited[r-1][c] = true;
                mat[r-1][c] = 2;
                q.push({r-1,c});
            }
            if(c+1 < m && mat[r][c+1] == 1 && visited[r][c+1] == false){
                flag = 1;
                visited[r][c+1] = true;
                mat[r][c+1] = 2;
                q.push({r,c+1});
            }
            if(c-1 >= 0 && mat[r][c-1] == 1 && visited[r][c-1] == false){
                flag = 1;
                visited[r][c-1] = true;
                mat[r][c-1] = 2;
                q.push({r,c-1});
            }
        }
        if(flag == 1) ans++;
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

    vector<vector<bool>>visited;
    for(int i=0; i<n; i++){
        vector<bool>temp;
        for(int j=0; j<m; j++){
            temp.push_back(false);
        }
        visited.push_back(temp);
    }
    int flag = 0;
    bfs(mat,visited,n,m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}
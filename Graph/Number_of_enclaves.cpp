#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>mat, vector<vector<bool>>&visited, int n, int m){
    int cnt = 0;
    queue<pair<int,int>>q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(((i==0) || (i == n-1) || (j==0) || (j==m-1)) && mat[i][j] == 1){
                visited[i][j] = true;
                mat[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        pair<int,int>p = q.front();
        int r = p.first, c = p.second;
        q.pop();

        int arr1[] = {1,-1,0,0}, arr2[] = {0,0,1,-1};
        for(int i=0; i<4; i++){
            if(r+arr1[i] >= 0 && r + arr1[i] < n && c+arr2[i] >= 0 && c+arr2[i] < m && visited[r+arr1[i]][c+arr2[i]] == false && mat[r+arr1[i]][c+arr2[i]] == 1){
                visited[r+arr1[i]][c+arr2[i]] = true;
                mat[r+arr1[i]][c+arr2[i]] = 0;
                q.push({r+arr1[i],c+arr2[i]});
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1){
                cnt++;
            }
        }
    }
    return cnt;

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

    vector<vector<bool>>visited;
    for(int i=0; i<n; i++){
        vector<bool>temp;
        for(int j=0; j<m; j++){
            temp.push_back(false);
        }
        visited.push_back(temp);
    }

    cout<<bfs(mat,visited,n,m)<<endl;

}
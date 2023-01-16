#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>&mat, vector<vector<bool>>&visited, int n, int m){
    queue<pair<int,int>>q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(((i==0) || (i == n-1) || (j==0) || (j==m-1)) && mat[i][j] == 'O'){
                visited[i][j] = true;
                mat[i][j] = 'M';
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
            if(r+arr1[i] >= 0 && r + arr1[i] < n && c+arr2[i] >= 0 && c+arr2[i] < m && visited[r+arr1[i]][c+arr2[i]] == false && mat[r+arr1[i]][c+arr2[i]] == 'O'){
                visited[r+arr1[i]][c+arr2[i]] = true;
                mat[r+arr1[i]][c+arr2[i]] = 'M';
                q.push({r+arr1[i],c+arr2[i]});
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 'O'){
                mat[i][j] = 'X';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 'M'){
                mat[i][j] = 'O';
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>mat;
    for(int i=0; i<n; i++){
        vector<char>temp;
        for(int j=0; j<m; j++){
            char ch;cin>>ch;
            temp.push_back(ch);
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
    bfs(mat,visited,n,m);

}
#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    if(source == destination) return 0;
    int n = grid.size(), m = grid[0].size();
    int dis[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dis[i][j] = INT_MAX; 
        }
    }
    dis[source.first][source.second] = 0;
    int ans = 0;
    
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{source}});
    while(!q.empty()){
        pair<int,int>node = q.front().second;
        int min_d = q.front().first;
        if(node == destination) return min_d;
        q.pop();
        int arr1[] = {1,-1,0,0}, arr2[] = {0, 0, 1, -1};
        for(int i=0; i<4; i++){
            int r = node.first + arr1[i];
            int c = node.second + arr2[i];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1 && min_d + 1 < dis[r][c]){
                dis[r][c] = min_d+1;
                q.push({min_d+1, {r,c}});
            }
        }
    }
    return -1;
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid;
    for(int i=0; i<n; i++){
        vector<int>temp;
        for(int i=0; i<m; i++){
            int var;cin>>var;
            temp.push_back(var);
        }
        grid.push_back(temp);
    }
    int src_row,src_col, dest_row,dest_col;
    cin>>src_row>>src_col>>dest_row>>dest_col;
    pair<int,int>src = {src_row,src_col},dest = {dest_row,dest_col};
    cout<<shortestPath(grid,src,dest)<<endl;
}
#include<bits/stdc++.h>
using namespace std;


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
    vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
    int ans = 0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    q.push({0,{0,0}});
    effort[0][0] = 0;
    while(!q.empty()){
        int ht_diff = q.top().first;
        int r = q.top().second.first, c = q.top().second.second;
        if(r == n-1 && c == m-1){
            cout<<ht_diff<<endl;
            break;
        }
        q.pop();
        int arr1[] = {1,-1,0,0}, arr2[] = {0,0,1,-1};
        for(int i=0; i<4; i++){
            int nr = r+arr1[i], nc = c+arr2[i];
            if(nr>=0 && nr < n && nc >= 0 && nc < m){
                int nh = abs(mat[r][c] - mat[nr][nc]);
                if(nh < effort[nr][nc]){
                    effort[nr][nc] = nh;
                    ans = max(ht_diff,nh);
                    q.push({ans,{nr,nc}});
                }
                
            }
        }
    }
    cout<<ans<<endl;
}
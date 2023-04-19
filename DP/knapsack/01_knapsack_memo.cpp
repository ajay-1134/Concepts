#include<bits/stdc++.h>
using namespace std;


int ks(int wt[], int val[], int n, int w, vector<vector<int>>&dp){
    if(n == 0 || w == 0){
        return 0;
    }
    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    if(wt[n-1] <= w){
        return dp[n][w] = max(val[n-1] + ks(wt,val,n-1,w-wt[n-1],dp), ks(wt,val,n-1,w,dp));
    }
    else return dp[n][w] = ks(wt,val,n-1,w,dp);
}

int main(){
    int n,w;
    cin>>n>>w;
    int wt[n], val[n];
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    vector<vector<int>>dp(n+1, vector<int>(w+1,-1));
    int res = ks(wt,val,n,w,dp);
    cout<<res<<endl;
    return 0;
}
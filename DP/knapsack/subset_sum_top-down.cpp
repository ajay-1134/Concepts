#include<bits/stdc++.h>
using namespace std;

bool ss(int n, vector<int>arr, int sum, vector<vector<int>>&dp ){
    for(int j=0; j<=sum; j++){
        dp[0][j] = 0;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j] = dp[i-1][j-arr[i-1]] | dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n;cin>>n;
    vector<int>arr;
    for(int i=0; i<n; i++){
        int var;cin>>var;
        arr.push_back(var);
    }
    int sum;cin>>sum;
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    cout<<ss(n,arr,sum,dp)<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

bool ss(int n, int arr[], int sum,vector<vector<int>>&dp){
    if(sum < 0) return false;
    if(n == 0){
        if(sum == 0){
            cnt++;
            return true;
        }
        else return false;
    }
    if(dp[n][sum] != -1){
        if(dp[n][sum] == 1){
            cnt+;
            return 1;
        }
        else return false;
    }

    if(arr[n-1] <= sum){
        if( ss(n-1,arr,sum-arr[n-1],dp) || ss(n-1,arr,sum,dp) ){
            cnt++;
            return dp[n][sum] = true;
        }
        return dp[n][sum] = false;
    }
    else{
        if( ss(n-1,arr,sum,dp) ){
            cnt++;
            return dp[n][sum] = true;
        }
        return dp[n][sum] =  false;
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum;cin>>sum;
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    if(ss(n,arr,sum,dp))    cout<<cnt<<endl;
    else cout<<"There is no subset Exists"<<endl;
}
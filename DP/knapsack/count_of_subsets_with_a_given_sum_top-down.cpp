#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int ss(int n, int arr[], int sum){
    int ans = 0;
    int dp[n+1][sum+1];
    for(int j=0; j<=sum; j++){
        dp[0][j] = 0;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                dp[i][j] = dp[i][j]%mod;
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum]%mod;
}

int main(){
    int n, sum;cin>>n>>sum;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<ss(n,arr,sum)%mod<<endl;
}
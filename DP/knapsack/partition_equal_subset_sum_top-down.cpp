#include<bits/stdc++.h>
using namespace std;



bool ss(int n, int arr[], int sum){
    int dp[n+1][sum+1];
    // if(sum < 0 ) return false;
    // if(n == 0){
    //     if(sum == 0) return true;
    //     else return false;
    // }
    for(int j=0; j<=sum; j++){
        dp[0][j] = 0;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    // if(dp[n][sum] != -1) return dp[n][sum];
    // return dp[n][sum] = ss(n-1,arr,sum-arr[n-1],dp) | ss(n-1,arr,sum,dp);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(j-arr[i-1]>=0){
                dp[i][j] = dp[i-1][j-arr[i-1]] | dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum%2 != 0){
        cout<<"NO"<<endl;
    }
    else{
        sum/=2;
        if(ss(n,arr,sum)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

int dp[101][100001];

bool ss(int arr[], int n, int sum){
    if(n == 0){
        if(sum == 0) return true;
        else return false;
    }
    if(dp[n][sum] != -1) return dp[n][sum];

    return dp[n][sum] = ss(arr,n-1,sum-arr[n-1]) | ss(arr,n-1,sum);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ;i<n; i++){
        cin>>arr[i];
    }
    int sum;cin>>sum;
    memset(dp,-1,sizeof(dp));
    cout<<ss(arr,n,sum)<<endl;
}
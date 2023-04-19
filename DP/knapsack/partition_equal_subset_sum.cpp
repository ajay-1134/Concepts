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
    int sum = 0;
    for(int i=0 ;i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum%2 != 0){
        cout<<"NO"<<endl;
    }
    else{
        sum/=2;
        memset(dp,-1,sizeof(dp));
        if(ss(arr,n,sum)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}
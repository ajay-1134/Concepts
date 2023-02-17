#include<bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    int n = arr.size();
    queue<pair<int,int>>q;
    vector<int>min_steps(100000,INT_MAX);
    q.push({0,start});
    while(!q.empty()){
        int steps = q.front().first, curr = q.front().second;
        if(curr == end) return steps;
        q.pop();
        for(int i=0; i<n; i++){
            int temp = (curr*arr[i])%100000;
            if(steps+1 < min_steps[temp]){
                min_steps[temp] = steps+1;
                q.push({steps+1,temp});
            }
        }
    }
    return -1;
}

int main(){
    int n,start,end;
    cin>>n>>start>>end;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<minimumMultiplications(arr,start,end);
}
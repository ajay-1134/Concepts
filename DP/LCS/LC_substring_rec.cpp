#include<bits/stdc++.h>
using namespace std;

int ans = 0;

int lcs(string s1, string s2, int n, int m){
    if(n == 0 || m == 0) return 0;

    if(s1[n-1] == s2[m-1]) return 1 + lcs(s1,s2,n-1,m-1);
    return 0;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
}
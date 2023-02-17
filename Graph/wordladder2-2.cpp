#include<bits/stdc++.h>
using namespace std;


vector<vector<string>>ans;
void dfs(vector<string>v,string curr, int curr_level, map<string,int>mp){
    if(curr_level == 0){
        reverse(v.begin(),v.end());
        ans.push_back(v);
        return;
    }
    int sz = curr.length();
    // cout<<sz<<endl;
    for(int i=0; i<sz; i++){
        for(char ch = 'a'; ch <= 'z'; ch++){
            string temp = curr;
            temp[i] = ch;
            if(temp != curr && mp.find(temp) !=mp.end() && mp[temp] == curr_level-1){
                vector<string>v1 = v;
                v1.push_back(temp);
                dfs(v1,temp,curr_level-1,mp);
            }
        }
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>st(wordList.begin(), wordList.end());
    map<string,int>mp;
    queue<pair<string,int>>q;
    q.push({beginWord,0});
    st.erase(beginWord);
    while(!q.empty()){
        string s = q.front().first; int level = q.front().second;
        if(s == endWord){
            vector<string>v(1,endWord);
            dfs(v,endWord,level,mp);
            return ans;
        }
        mp[s] = level; 
        q.pop();
        int sz = s.length();
        for(int i=0; i<sz; i++){
            for(char ch = 'a'; ch<='z'; ch++){
                string temp = s;
                temp[i] = ch;
                if(temp != s && st.find(temp) != st.end()){
                    q.push({temp,level+1});
                    st.erase(temp);
                }
            }
        }
    }
    
    return ans;
}



int main(){
    int n;
    cin>>n;
    vector<string>wordList;
    for(int i=0; i<n; i++){
        string var;cin>>var;
        wordList.push_back(var);
    }
    string beginWord, endWord;
    cin>>beginWord>>endWord;

    vector<vector<string>>ans = findLadders(beginWord,endWord,wordList);
    int total = ans.size();
    for(int i=0; i<total; i++){
        for(auto j:ans[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

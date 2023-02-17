#include<bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    int n = wordList.size();
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<pair<string,int>>q;
    q.push({startWord,1});
    st.erase(startWord);
    while(!q.empty() ){
        string s = q.front().first; int cnt =  q.front().second;
        if(s == targetWord) return cnt;
        q.pop();
        int sz = s.length();
        for(int i=0; i<sz; i++){
            for(char ch = 'a'; ch <= 'z'; ch++){
                string temp = s;
                temp[i] = ch;
                if(s!=temp && st.find(temp) != st.end()){
                    q.push({temp,cnt+1});
                    st.erase(temp);
                }
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<string>wordList;
    for(int i=0; i<n; i++){
        string var;cin>>var;
        wordList.push_back(var);
    }
    string startWord, targetWord;
    cin>>startWord>>targetWord;
    cout<<wordLadderLength(startWord,targetWord,wordList)<<endl;
}
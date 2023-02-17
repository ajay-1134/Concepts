#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>>ans;
    unordered_set<string>st(wordList.begin(), wordList.end());
    queue<vector<string>>q;
    vector<string>v(1,beginWord);
    q.push(v);
    st.erase(beginWord);
    while(!q.empty()){
        int qsz = q.size();
        set<string>to_dlt;
        for(int i=0; i<qsz; i++){
            vector<string>temp = q.front();
            q.pop();
            string s = temp[temp.size() - 1];
            if(s == endWord){
                ans.push_back(temp);
            }
            int ssz = s.length();
            for(int i=0; i<ssz; i++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    string tempp= s;
                    tempp[i] = ch;
                    if(tempp != s && st.find(tempp) != st.end()){
                        vector<string>v1 = temp;
                        v1.push_back(tempp);
                        to_dlt.insert(tempp);
                        q.push(v1);
                    }
                }
            }
        }
        for(auto i:to_dlt){
            st.erase(i);
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

    vector<vector<string>>ans = findSequences(beginWord,endWord,wordList);
    int total = ans.size();
    for(int i=0; i<total; i++){
        for(auto j:ans[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
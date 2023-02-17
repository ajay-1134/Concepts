#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == -1) matrix[i][j] = INT_MAX;
        }
    }
    for(int via=0; via<n; via++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == via || j == via ||i==j){
                    continue;
                }
                else{
                    if(matrix[i][via] == INT_MAX || matrix[via][j] == INT_MAX){
                        continue;
                    }
                    if(matrix[i][via] + matrix[via][j] < matrix[i][j]){
                        matrix[i][j] = matrix[i][via]+matrix[via][j];
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == INT_MAX) matrix[i][j] = -1;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>matrix;
    for(int i=0; i<n; i++){
        vector<int>temp(n);
        for(int j=0; j<n; j++){
            cin>>temp[j];
        }
        matrix.push_back(temp);
    }

    shortest_distance(matrix);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


}
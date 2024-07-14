#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> transpose(vector <vector<int>> v){
    vector<vector<int>> v2(v[0].size(), vector<int>(v.size()));
    for (int i = 0; i < v[0].size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            v2[i][j] = v[j][i];
        }
    }
    return v2;
}

int main(){
    vector<vector<int>> v3={
        {1,2,3} ,
        {4,5,6} ,
        {7,8,9}
    };
    vector<vector <int>> vret=transpose(v3);
    for(auto &row: vret){
        for(auto &elem: row){
            cout << elem << " ";
        }
        cout << "\n";
    }
    return 0;
}
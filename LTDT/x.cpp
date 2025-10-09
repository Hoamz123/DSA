#include<bits/stdc++.h>
using namespace std;

int countDays(int d, vector<vector<int>>& m) {
    sort(m.begin(), m.end());
    vector<vector<int>> v;
    v.push_back(m[0]);
    for(int i=1;i<(int)m.size();i++){
        int enBack = v.back()[1];
        int sNow = m[i][0];
        int eNow = m[i][1];
        if(sNow > enBack){
            v.push_back({sNow,eNow});
        }
        else if(sNow <= enBack){
            if(sNow == eNow){
                v.push_back({0,-1});
            }
            if(enBack + 1 <= eNow){
                v.push_back({enBack + 1,eNow});
            }
        }
    }
    int cnt = 0;
    for(auto it : v){
        cnt += (it[1] - it[0] + 1);
    }
    return d - cnt;
}



int main(){
    vector<vector<int>> v = {{3, 4}, {4, 8}, {2, 5}, {3, 8}};
    cout << countDays(8,v);
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<pair<int,int>> p;
    for (int j = 0; j < n; j++){
        int s,e;cin >> s >> e;
        p.push_back({s,1});
        p.push_back({e,-1});
    }
    int curr = 0;
    int ans = 0;
    sort(p.begin(),p.end());
    for(auto &[s,number] : p){
        curr += number;
        ans = max(ans,curr);
    }
    cout << ans;
}
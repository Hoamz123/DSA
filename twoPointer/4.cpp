#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,s;cin >> n >> s;
    vector<int> a(n,0);
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = 0;
    for(int x : a){
        int pad = s - x;
        res += mp[pad];
        mp[x]++;
    }
    cout << res;
}
#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1138/A
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    vector<int> res;
    int i=0;
    while(i < n){
        int dem = 1;
        while(i + 1 < n && a[i] == a[i+1]){
             dem++;
             i++;
        }
        i++;
        res.push_back(dem);
    }
    int rs = -1e9;
    for(int i=0;i<(int)res.size() - 1;i++){
        rs = max(rs,2 * min(res[i],res[i+1]));
    }
    cout << rs;
    //acc
}
//day con tang dai nhat

#include<bits/stdc++.h>
using namespace std;
/**
 * LIS
 * Muong tim giam dai nhat thay vi search a[i] thi search -a[i]
 */
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin >> n;
    vector<int >a(n);
    for(int &x : a) cin >> x;
    vector<int> res;
    for(int i=0;i<n;i++){
        auto it = lower_bound(res.begin(),res.end(),a[i]);
        if(it == res.end()) res.push_back(a[i]);
        else *it = a[i];
    }
    cout << res.size();
}
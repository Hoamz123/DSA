#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin >> n;
    vector<int> a(n,0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int x = a[n / 2];
    ll res = 0;
    for(int i : a){
        res += abs(i - x);
    }
    cout << res;
}
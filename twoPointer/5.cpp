#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://oj.vnoi.info/problem/ndccard (acc) y tuong nhu bao three sum
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin >> n >> m;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int res = 0;
    sort(a.begin(),a.end());
    for(int i=0;i<n-2;i++){
        if(i > 0 && a[i] == a[i-1]) continue;
        int l = i+1,r = n-1;
        while(l < r){
            if(a[l] + a[r] == m - a[i]){
                cout << a[l] + a[r] + a[i];
                return 0;
            }
            else if(a[l] + a[r] > m - a[i]) r--;
            else if(a[l] + a[r] < m - a[i]){
                res = max(res,a[l] + a[r] + a[i]);
                while(l < n && a[l] == a[l+1]) l++;
                while(r > -1 && a[r] == a[r-1]) r--;
                l++;
            }
        }
    }
    cout << res;
}
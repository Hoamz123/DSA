#include<bits/stdc++.h>
using namespace std;
//cho mang sort khong giam
//timvi tri i j, i!=j saocho a[i] + a[j] = x;
int main(){
    int n,s;cin >> n >> s;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    int l = 0,r = a.size() - 1;
    int res = 0;
    while(l <= r){
        if(a[l] + a[r] == s){
            cout << l << " " << r;
            return 0;
        }
        else if(a[l] + a[r] < s) l++;
        else r--;
    }
    cout << res;
}
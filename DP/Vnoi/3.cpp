#include<bits/stdc++.h>
using namespace std;
// https://oj.vnoi.info/problem/nktick
int main(){
    int n;cin >> n;
    vector<int> times(n+1);
    vector<int> r(n);
    for(int i=1;i<=n;i++){
        cin >> times[i];
    }
    for(int j=1;j<n;j++) cin >> r[j];
    vector<int> f(n+1,0);//f[i] la tong thoi gian mua ve cho i nguoi dau
    f[1] = times[1];
    for(int i=2;i<=n;i++){
        f[i] = min(f[i-1] + times[i],f[i-2] + r[i-1]);
    }
    cout << f[n];
}

/*
5
2 5 7 8 4
4 9 10 10
*/
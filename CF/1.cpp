#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
string s;
vector<int> pre(1e7);

int f(int i, bool add){
    if(s[i-1] == 'L' and s[i] == 'R' and pre[i] > i){
        if(add) cnt++;
        else cnt--;
    }
}

void solve(){
    cnt = 0;
    int n,q;
    cin>>n>>q;

    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    cin>>s;

    for(int i=1; i<=n; i++){
        pre[i] = max(pre[i-1], a[i]);
    }

    for(int i=1; i<n; i++) f(i, 1);
    
    for(int i=0; i<q; i++){
        int x; cin>>x;
        f(x, 0);
        f(x-1, 0);
        if(s[x-1] == 'L') s[x-1] = 'R';
        else s[x-1] = 'L';
        f(x, 1);
        f(x-1, 1);
        if(cnt > 0) cout<<"no\n";
        else cout<<"yes\n";
    }
}
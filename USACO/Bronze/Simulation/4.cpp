#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define pii pair<int, int>
#define vi vector<int>
#define si set<int>
#define pb push_back
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'

void solve(){
    int n,m;cin >> n >> m;
    vi gov(101);
    vector<pii> a1,a2;
    FOR1(i,n){
        int len,v;cin >> len >> v;
        a1.pb({len,v});
    }
    FOR1(i,m){
        int len,v;cin >> len >> v;
        a2.pb({len,v});
    }
    int start = 1;
    int end = 0;
    FOR0(i,n){
        int len = a1[i].first;int v = a1[i].second;
        end = start + len - 1;
        REP(j,start,end) gov[j] = v;
        start = end + 1;
    }
    int ans = 0;
    start = 1;
    end = 0;
    FOR0(i,m){
        int len = a2[i].first;int v = a2[i].second;
        end = start + len - 1;
        REP(j,start,end){
            if(gov[j] < v) ans = max(ans,v - gov[j]);
        }
        start = end + 1;
    }
    cout << ans;
}

int main(){
    faster();
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    solve();
}
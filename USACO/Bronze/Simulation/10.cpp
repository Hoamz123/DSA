#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umi unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define fi first
#define se second

void solve(){
    int n;cin >> n;
    int res[26] = {0};
    FOR1(i,n){
        int a[26] = {0};int b[26] = {0};int r[26] = {0};
        string s,t;cin >> s >> t;
        FOR0(i,(int)s.size()){
            a[s[i] - 'a']++;
        }
        FOR0(i,(int)t.size()){
            b[t[i] - 'a']++;
        }
        FOR0(i,26){
            r[i] = max(a[i],b[i]);
        }
        FOR0(i,26){
            res[i] += r[i];
        }
    }
    REP(i,0,25) {
        cout << res[i] << endl;
    }
}

int main(){
    faster();
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}

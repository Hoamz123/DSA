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
    vector<pii> a;
    vi pos;
    FOR0(i,n){
        char c;int x;cin >> c >> x;
        a.pb({c,x});
        pos.pb(x);
    }
    int cnt = INF;
    //duyet lan luot cac pos duoc nhac den (ung voi tung pos se check xem con co bao nhieu con bo dang noi doi)
    for(int p : pos){
        int tmp = 0;
        for(auto &[c,x] : a){
            if(c == 'L' && p > x) tmp++;
            if(c == 'G' && p < x) tmp++;
        }
        cnt = min(tmp,cnt);
    }
    cout << cnt;
}


int main(){
    faster();
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
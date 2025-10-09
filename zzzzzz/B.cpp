#include <bits/stdc++.h>
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
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    FOR0(i, n) cin >> a[i];
    int m = *min_element(a.begin(), a.end());
    FOR0(i, n) cin >> b[i];

    int sum = -1;
    FOR0(i, n) {
        if (b[i] != -1) {
            int cur = a[i] + b[i];
            if (sum == -1) sum = cur;
            else if (sum != cur) {
                cout << 0 << endl;
                return;
            }
        }
    }

    int minSum = *max_element(a.begin(), a.end());
    if (sum != -1) {
        if (sum < minSum) cout << 0 << endl;
        else {
            int pad = sum - m;
            if (pad > k || pad < 0) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }
    else {
        int l = *max_element(a.begin(), a.end());
        int r = *min_element(a.begin(), a.end()) + k;
        int ways = max(0LL, r - l + 1);
        cout << ways << endl;
    }
}

int32_t main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
}

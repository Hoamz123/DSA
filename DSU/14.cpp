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
#define ull unsigned long long
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'

map<pii,ll> solve(vector<pii> &v) {
    map<pii, ll> m;
    int sz = v.size();
    for (int mask = 0; mask < (1 << sz); mask++) {
        ll x = 0, y = 0;
        for (int i = 0; i < sz; ++i) {
            if ((mask >> i) & 1) {
                x += v[i].first;
                y += v[i].second;
            }
        }
        m[{x, y}]++;
    }
    return m;
}

int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    vector<pii> A(v.begin(), v.begin() + n / 2);
    vector<pii> B(v.begin() + n / 2, v.end());

    map<pii, ll> mapA, mapB;
    mapA = solve(A);
    mapB = solve(B);

    ll res = 0;
    for (auto &[p, cntA] : mapA) {
        ll dx1 = p.first, dy1 = p.second;
        ll dx2 = a - dx1, dy2 = b - dy1;
        res += 1ll * cntA * mapB[{dx2, dy2}];
    }
    cout << res << endl;
}
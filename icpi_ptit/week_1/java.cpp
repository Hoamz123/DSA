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

int a[1000005];
int ok = 0;

void sinh(int n){
    int m = n - 1;
    int i = m;
    while(i >= 0 && a[i]){
        a[i] = 0;
        --i;
    }
    if(i == -1) ok = 1;
    else a[i] = 1;
}

ll ltnp(ll a,ll b){
    a %= mod;
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long max_a_i = a[0];
    long long max_val_j = LLONG_MIN;
    long long result = LLONG_MIN;

    for(int k = 2; k < n; k++) {
        long long val_j = 2*a[k-1] + max_a_i;
        max_val_j = max(max_val_j, val_j);

        // tính f(i,j,k) với k hiện tại
        result = max(result, 3*a[k] + max_val_j);

        // cập nhật max_a_i cho j tiếp theo (trước k)
        max_a_i = max(max_a_i, a[k-1]);
    }

    cout << result << "\n";
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    //SQL Server
    int t;cin >> t;
    while(t--){
        solve();
    }
}
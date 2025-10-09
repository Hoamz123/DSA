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

//cho mang n*n,cac vi tri co quan hau la 1 else la 0
// duong cheo chinh i - j
// duong cheo phu i + j

ll nC2(ll n){
    return n * (n - 1) / 2;
}

vector<vi> a;
void solve_(){
    int n;cin >> n;
    a.assign(n,vi(n));
    FOR0(i,n)FOR0(j,n) cin >> a[i][j];
    unordered_map<int,int> row,col,diag_1,diag_2;
    FOR0(i,n)FOR0(j,n){
        if(a[i][j]){
            row[i]++;
            col[j]++;
            diag_1[i - j]++;
            diag_2[i + j]++;
        }
    }
    ll ans = 0;
    for(auto it : row){
        ans += nC2(it.second);
    }
    for (auto it : col){
        ans += nC2(it.second);
    }
    for (auto it : diag_1){
        ans += nC2(it.second);
    }
    for(auto it : diag_2){
        ans += nC2(it.second);
    }
    cout << ans;
}


ll count_pairs(ll k) {
    return k * (k - 1) / 2;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    
    // Nhập ma trận
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    vector<int> row(n, 0), col(m, 0);
    unordered_map<int, int> diag1, diag2; // diag1: i - j, diag2: i + j

    // Duyệt qua ma trận, đếm quân hậu theo từng hướng
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == 1) {
                row[i]++;
                col[j]++;
                diag1[i - j]++;
                diag2[i + j]++;
            }

    ll res = 0;
    for (int i = 0; i < n; ++i) res += count_pairs(row[i]);
    for (int j = 0; j < m; ++j) res += count_pairs(col[j]);
    for (auto p : diag1) res += count_pairs(p.second);
    for (auto p : diag2) res += count_pairs(p.second);

    cout << res << endl;
    return;
}


int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve_();
    }
}
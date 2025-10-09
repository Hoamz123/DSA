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
    ll n,m;cin >> n >> m;
    vector<ll> a(n + 1),b(n + 1);
    FOR1(i,n) cin >> a[i];
    FOR1(i,m) cin >> b[i];
    vector<ll> pre(n + 99,0),suf(n + 99,0);

    //tinh prefix : so phan tu dau cua b co the lay tu trai sang phai
    ll idx = 1;
    REP(i,1,n){
        if(a[i] >= b[idx] && idx <= m){
            pre[i] = pre[i - 1] + 1;
            idx++;
        }
        else pre[i] = pre[i-1];
    }

    //tinh suf : so phan tu cuoi cua b co the lay tu phai snag
    idx = m;
    PER(i,n,1){
        if(a[i] >= b[idx] && idx > 0){
            suf[i] = suf[i + 1] + 1;
            idx--;
        }
        else suf[i] = suf[i + 1];
    }

    //case du ma ko can chen
    if(pre[n] >= m || suf[1] >= m){
        cout << 0 << endl;
        return;
    }

    ll LNF = 1ll * INF * INF;
    ll ans = LNF;

    //case 2 : phai chen
    REP(i,0,n){
        ll left = pre[i];
        ll right = suf[i + 1];

        if(left + right >= m){
            ans = 0;
        }
        else if(left + right + 1 >= m){
            ans = min(ans,b[left + 1]);
        }
    }
    if(ans == LNF) cout << -1 << endl;
    else cout << ans << endl;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
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

void solve_1(){
    string s;cin >> s;
    int n = s.size();
    vi pre_u(n,0);
    vi pre_i(n,0);
    pre_u[0] = (s[0] == 'U');
    for(int i=1;i<n;i++){
        if(s[i] == 'U'){
             pre_u[i] = pre_u[i-1] + 1;
        }
        else pre_u[i] = pre_u[i-1];
    }
    pre_i[0] = (s[0] == 'I');
    for(int i=1;i<n;i++){
        if(s[i] == 'I'){
            pre_i[i] = pre_i[i-1] + 1;
        }
        else pre_i[i] = pre_i[i-1];
    }
    for(int i=0;i<n;i++){
        if(pre_i[i] > 0 && pre_u[i] > 0
            && (pre_i[i] >= 2 * pre_u[i]
                || pre_u[i] >= 2 * pre_i[i])){
            cout << "Yes ";
            cout << 1 << ' ' << i + 1 << endl;
            return;
        }
    }
    cout << "NO\n";
}


void solve_2(){
    ll n,m;cin >> n >> m;
    if(n == 1 || n > m || m % n){
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    while(n != m){
        int t = __gcd(n,m/n);
        if(t == 1){
            cout << -1 << endl;
            return;
        }
        n = 1ll * n * t;
        ans.pb(t);
    }
    cout << (int)ans.size() << " ";
    for(int i: ans) cout << i << ' ';
    cout << endl;
    //acc
}

#define ull unsigned long long
vector<ull> socpht, lncr, cttv;
ull tct = 0;
/**
 * tct : tong co tuc phai chia cho cac co dong tu truoc den bayh
 * socpht[p] tong so co phieu ma co dong p dang nam giu
 * lncr[p] loi nhuan cua co dong p (co the rut)
 * cttv[p] : tong so co tuc ma co dong p da thu ve truoc do
 */
void update(int p){
    //x la so co tuc bayh phai chia cho co dong p = tong so co tuc phai chia cho cac co dong  - so co tuc ma truoc do co dong p da nhan
    ull x = (tct - cttv[p]) % mod;
    cttv[p] = tct;//gan
    lncr[p] = (lncr[p] % mod + socpht[p] % mod * x % mod) % mod;//loi nhuan tang them = so co phieu dang co * so co tuc can nhan
}

void solve_3(){
    int n,q;cin >> n >> q;
    socpht.resize(n);
    lncr.resize(n);
    cttv.resize(n);
    while(q--){
        int t;cin >> t;
        if(t == 1){
            int p,x;cin >> p >> x;
            --p;
            update(p);
            socpht[p] += x;
        }
        else if(t == 2){
            int v;cin >> v;
            tct += v;
        }
        else if(t == 3){
            int p;cin >> p;
            --p;
            update(p);
            cout << lncr[p] << endl;
            lncr[p] = 0;
        }
    }
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve_3();
    }
    //acc
}
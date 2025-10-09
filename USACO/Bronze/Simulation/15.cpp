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
#define LINF = 2e18;
#define nax 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define fi first
#define se second
int n;
ll tC,tM;
ll x[111],y[111],c[111];

///kiem tra xem xau khi nang cap a,b thi co thoa man hay khong
bool check(ll a,ll b){
    FOR0(i,n){
        if((tC - a) * x[i] + (tM - b) * y[i] > c[i]) return false;
    }
    return true;
}

//khi giam tc di 1 luong a -> dung bs de tim luong giam nho nhat cua tm
ll bin(ll a){
    ll low = 0,high = tM - 1;
    if(!check(a,high) || a < 0 || a >= tC) return LINF;
    ll res;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(check(a,mid)){
            res = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return res + a;//luong giam nho nhat khi da giam tc di a don vi
}


void solve(){
    cin >> n >> tC >> tM;
    ll ans = tC + tM - 2;
    FOR0(i,n) cin >> x[i] >> y[i] >> c[i];

    for(int t = 0;t<2;t++){
        ll low = 0,high = tC;
        //tam phan
        while(high - low > 3){
            ll m = (high - low) / 3;//chia lam ba doan
            ll fi = bin(low + m);
            ll se = bin(high - m);
            if(fi > se || fi == LINF) low += m;
            else high -= m;
        }
        for(ll i = low;i<=high;i++){
            ans = min(ans,bin(i));
        }
        swap(tC,tM);
        FOR0(i,n) swap(x[i],y[i]);
    }
    cout << ans << endl;
}

int main(){
    faster();
    int t;cin >> t;
    while(t--){
        solve();
    }
}
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

void solve(){
    set<ll> se;
    for(ll i = 1;i<=1e18;i*=2){
        for(ll j = i;j<=1e18;j*=3){
            for(ll k = j;k<=1e18;k*=5){
                se.insert(k);
            }
        }
    }
    vll v(se.begin(),se.end());
    int q;cin >> q;
    while(q--){
        ll m;cin >> m;
        auto it = lower_bound(v.begin(),v.end(),m);
        if(it == v.end() || *it != m) cout << -1;
        else cout << it - v.begin() + 1;//do chi so chay tu 1
        cout << endl;
    }
}

//cach nen lam
void _solve(){
    vector<ll> v = {1};//bat dau sinh tu 1
    int i2 = 0,i3 = 0,i5 = 0;
    while(true){
        ll next2 = v[i2] * 2;
        ll next3 = v[i3] * 3;
        ll next5 = v[i5] * 5;
        ll next = min({next2,next3,next5});
        if(next > 1e18) break;//dung
        v.push_back(next);
        if(next == next2) i2++;
        if(next == next3) i3++;
        if(next == next5) i5++;
    }
    //da co list 
    int q;cin >> q;
    while(q--){
        ll m;cin >> m;
        auto it = lower_bound(v.begin(),v.end(),m);
        if(it == v.end() || *it != m){
            cout << -1 << endl;
        }
        else cout << it - v.begin() + 1 << endl;
    }
}

/*
tong quat khi no khong chi la 2 3 5 nua ma se la 1 mang
*/

//viet ham tra ve mot list cac so thoa man nhung luc nay khong chi la 2,3,5 nua ma la mot mang
vll res(const vi &a,int n){
    //a la mang cac so nguyen to
    //tra ve mang co n so dau tien
    vll s(n);
    s[0] = 1;
    int k = a.size();
    vi idx(k,0);
    for(int i=1;i<n;i++){
        ll next = LLONG_MAX;
        for(int j=0;j<k;j++){
            next = min(next,s[idx[j]] * a[j]);
        }
        s[i] = next;
        for(int j=0;j<k;j++){
            if(next == s[idx[j]] * a[j]) idx[j]++;
        }
    }
    return s;
}

void solve__(){
    vi a = {2,3,5};
    int n = 10;
    vll ans = res(a,n);
    for(ll x : ans) cout << x << ' ';
}


int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve__();
    }
}

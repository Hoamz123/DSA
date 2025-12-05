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

int bs(const vi &a,int x){
    int l = 0,r = (int)a.size() - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(x == a[m]) return m + 1;
        else if(x < a[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

void solve(){
    int n,q;cin >> n >> q;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    while(q--){
        int x;cin >> x;
        cout << bs(a,x) << endl;
    }
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}

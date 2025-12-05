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

bool cmd(pii &a,pii &b){
    return a.second < b.second;
}

void solve(){
    int n,q;cin >> n >> q;
    vector<pii> v;
    for(int i=0;i<n;i++){
        int a,w;cin >> a >> w;
        v.push_back({a,w});
    }
    sort(v.begin(),v.end(),cmd);
    vll fre(n,0);
    fre[0] = v[0].first;
    for(int i=1;i<n;i++) fre[i] = fre[i-1] + v[i].first;

    while(q--){
        ll k;cin >> k;
        ll pos = lower_bound(fre.begin(),fre.end(),k) - fre.begin();
        cout << v[pos].first << endl;
    }
}

int main(){
    faster();
    solve();
}

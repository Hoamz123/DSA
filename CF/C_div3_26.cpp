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
    int n;cin >> n;
    vi a(n);
    FOR0(i,n) cin >> a[i];
    si se;
    se.insert(a[0]);
    int pivot = a[0];
    FOR1(i,n-1){
        if(a[i] - pivot > 1){
            se.is(a[i]);
            pivot = a[i];
        }
    }
    cout << (int)se.size() << endl;
}
//acc

int main(){
    faster();
    int t;cin >> t;
    while(t--){
        solve();
    }
}
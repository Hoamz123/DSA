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
    vi a(n+1);
    FOR1(i,n) cin >> a[i];
    int m = INF;
    
    FOR1(i,n){
        int sum = 0;
        int x = 1;
        //bat dau di tu i + 1
        REP(j,i + 1,n){
            sum += (a[j] * x);
            x++;
        }
        REP(j,1,i-1){
            sum += (a[j] * x);
            x++;
        }
        m = min(m,sum);
    }
    cout << m;
}

int main(){
    faster();
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
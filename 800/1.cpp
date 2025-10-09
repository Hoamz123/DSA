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
    int n,k;cin >> n >> k;
    vi a(n);
    FOR0(i,n) cin >> a[i];
    vi b = a;
    sort(b.begin(),b.end());
    if(k == 1){
        // k = 1 thi ko swap dc cai gi
        if(a == b){
            //da sort
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    //neu k >= 2 ta luon luon co the dua ve dang khong giam
    else if(k >= 2){
        cout << "YES\n";
    }
}

int main(){
    faster();
    int t;cin >> t;
    while(t--){
        solve();
    }
}
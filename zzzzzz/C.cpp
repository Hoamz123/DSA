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
    int n,x;cin >> n >> x;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    ///0 -> .... x - 1
    if(x == 0){
        //case dac biet
        PER(i,n - 1,0) cout << i << ' ';
    }
    else if(x == n - 1){
        REP(i,0,n-1) cout << i << ' ';
    }
    else{
        set<int> se;
        REP(i,0,n-1){
            if(i == x) continue;
            else{
                se.is(i);
                cout << i << ' ';
            }
        }
        if((int)se.size() < n) cout << x;
    }
    cout << endl;
}
//acc
int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
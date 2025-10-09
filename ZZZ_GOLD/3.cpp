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
    cout << __builtin_popcount(5) << "\n"; // 5 = 0101 có 2 bit '1'
    int x = 8;
    x ^= (1 << 3);//doa bit tthu 3
    cout << x << endl;
    x ^= (1 << 3);
    if((x & ( 1 << 2))) cout << true;//check bit thu 2 cua x co phai bit 1 hay khong
}


void solve_(){
    int n,k;cin >> n >> k;
    vector<int> a(n,0);
    int res = 0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int mask = 0;mask < (1 << n);mask++){
        if(__builtin_popcount(mask) == k){
            for(int j=0;j<n;j++){
                if((mask >> j) & 1){
                    res += a[j];
                }
            }
        }
    }
    cout << res << endl;
    //acc
}



int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve_();
    }
}
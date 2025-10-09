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
    int n,q;cin >> n >> q;
    vi a(n + 1);
    FOR1(i,n) cin >> a[i];
    vi pre_1(n + 1,0);
    vi pre_2(n + 1, 0);
    vi pre_3(n + 1, 0);
    FOR1(i,n){
        if(a[i] == 1){
            pre_1[i] = pre_1[i-1] + 1;
            pre_2[i] = pre_2[i-1];
            pre_3[i] = pre_3[i - 1];
        }
        else if(a[i] == 2){
            pre_1[i] = pre_1[i - 1];
            pre_2[i] = pre_2[i - 1] + 1;
            pre_3[i] = pre_3[i - 1];
        }
        else{
            pre_1[i] = pre_1[i - 1];
            pre_2[i] = pre_2[i - 1];
            pre_3[i] = pre_3[i - 1] + 1;
        }
    }

    FOR1(i,q){
        int l,r;cin >> l >> r;
        cout << pre_1[r] - pre_1[l - 1] << ' ' << pre_2[r] - pre_2[l - 1] << ' ' << pre_3[r] - pre_3[l - 1] << endl;
    }

}

int main(){
    faster();
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define len length
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'

// void solve(){
//     //liet ke tat ca cac tap hop con cua n
//     int n = 10;
//     for(int sub = n;sub >= 0;sub--){
//         sub &= n;
//         cout << sub << endl;
//     }
// }


void solve(){
    int n;cin >> n;
    vi a(n);
    FOR0(i,n) cin >> a[i];
    FOR0(i,n) {
        int ans = 0;
        FOR0(j,n){
            if(j == i) continue;
            ans ^= a[j];
        }
        if(ans == a[i]){
            cout << ans << endl;
            break;
        }
    }
}

int main(){
    faster();

    int t;cin >> t;
    while(t--){
        solve();
        //acc
    }
    // https://codeforces.com/group/FcraNkfhvg/contest/554120/problem/A
}
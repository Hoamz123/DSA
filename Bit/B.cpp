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
    unordered_map<int,int> mp;
    FOR0(i,n){
        int a;cin >> a;
        mp[a]++;
    }
    //neu nhu tan xuat chan -> coi nhu ko xuat hien (vi chan lan xor coi nhu 0 lan xor,le lan xor coi nhu xuats hien 1 lan)
    vi ve;
    for(auto it : mp){
        if(it.second & 1) ve.push_back(it.first);
    }
    int m = ve.size();
    int ans = 0;
    FOR0(i,m) ans ^= ve[i];
    if(m % 2 == 0 && ans != 0) cout << -1 << endl;
    else cout << ans << endl;
}

int main(){
    faster();
    
    int t;cin >> t;
    while(t--){
        solve();
        //acc
    }
    // https://codeforces.com/group/FcraNkfhvg/contest/554120/problem/B
}
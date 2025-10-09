#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'


void solve() {
    int n;cin >> n;
    vi a(n+1);
    FOR1(i,n) cin >> a[i];
    FOR1(i,n){
        if(i == a[a[a[i]]]){
            cout << "<3\n";
            return;
        }
    }
    cout << "</3\n";
}


int main(){
    faster();
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
// https://oj.vnoi.info/problem/vnoicup23_r1_a
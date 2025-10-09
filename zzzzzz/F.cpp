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
    ll k;
    cin >> k;
    string s;cin >> s;
    ll len = (ll)s.size();
    if(k < len){
        cout << s[k - 1] << endl;
        return;
    }
    while(k > len){
        ll tmp = len;
        while(tmp * 2 < k) tmp *= 2;
        k = k - tmp - 1;
        if(k == 0) k = tmp;
    }
    cout << s[k - 1];
}

/*
8
RYUU
*/

int main(){
    faster();
    solve();
}
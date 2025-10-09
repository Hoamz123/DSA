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


//thuat euclid mo rong
/**
 * ax + by = GCD(a,b)
 */

int _gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a % b);
}

/**
 * x = y1
 * y = x1 - a/b * y1
 */

int gcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = gcd(b,a % b,x1,y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


void solve(){
    int x,y;
    gcd(8,5,x,y);
    cout << x << ' ' << y;
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
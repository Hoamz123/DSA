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

vector<ll> a,segMin,segMax;

void build(int id,int l,int r){
    if(l == r){
        segMax[id] = segMin[id] = a[l];
    }
    else{
        int mid = l + (r - l) / 2;
        build(id * 2,l,mid);
        build(id * 2 + 1,mid + 1,r);
        segMin[id] = min(segMin[id * 2],segMin[id * 2 + 1]);
        segMax[id] = max(segMax[id * 2],segMax[id * 2 + 1]);
    }
}

int get(int id,int l,int r,int u,int v,int type){//1 max,0 min
    if(v < l || u > r) {
        return (type == 1) ? -INF : INF;
    }
    if(u <= l && v >= r){
        return (type == 1) ? segMax[id] : segMin[id];
    }
    int mid = l + (r - l) / 2;
    int left = get(id * 2, l, mid, u, v, type);
    int right = get(id * 2 + 1, mid + 1, r, u, v, type);
    if(type == 1) return max(left, right);
    return min(left, right);
}

void solve(){
    int n,q;cin >> n >> q;
    a.resize(n + 1,0);
    segMin.resize(4 * n);
    segMax.resize(4 * n);
    FOR1(i,n) cin >> a[i];
    build(1, 1, n);
    FOR1(i,q){
        int a,b;cin >> a >> b;
        int m = get(1, 1, n, a, b, 0);
        int M = get(1, 1, n, a, b, 1);
        cout << M - m << endl;
    }
}
// https://oj.vnoi.info/problem/nklineup
int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    solve();
}
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

int a[nax],n;
vector<ll> seg;


void build(int v,int l,int r){
    //base case
    if(l == r) seg[v] = a[l];
    else{
        int mid = l + (r - l) / 2;
        build(2 * v,l,mid);
        build(2 * v + 1,mid + 1,r);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}

int get(int v,int tl,int tr,int l,int r){
    if(l > r) return 0;
    if(l == tl && r == tr) return seg[v];
    int tmid = (tl + tr) / 2;
    return get(2 * v,tl,tmid,l,min(tmid,r)) + get(2 * v + 1,tmid + 1,tr,max(tmid + 1,l),r);
}

//tong tu u den v
int get_(int id,int l,int r,int u,int v){
    if(v < l && r < u) return 0;
    if(v <= l && r <= u) return seg[id];
    int mid = (l + r) / 2;
    if(v <= mid) return get(id * 2,l,mid,u,v);
    if(u > mid) return get(id * 2 + 1,mid + 1,r,u,v);
    return get(id * 2,l,mid,u,mid) + get(id * 2 + 1,mid + 1,r,mid + 1,v);
}


void update(int id,int l,int r,int pos,int val){
    if(l == r) seg[id] = val;
    else{
        int mid = (l + r) / 2;
        if(pos <= mid) update(2 * id,l,mid,pos,val);
        else update(id * 2 + 1,mid + 1,r,pos,val);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
}


void solve(){
    cin >> n;
    FOR0(i,n) cin >> a[i];
    seg.resize(4 * n,0);
    build(1,0,n-1);
    //sum [2-3]
    cout << get_(1,0,n-1,2,3) << endl;
    //update a[2] = 10
    update(1,0,n-1,2,10);
    cout << get_(1,0,n-1,2,3);
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
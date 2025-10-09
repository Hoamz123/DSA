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

vector<ll> a,seg;

void build(int id,int l,int r){
    if(l == r) seg[id] = a[l];
    else{
        int mid = l + (r - l) / 2;
        build(id * 2,l,mid);
        build(id * 2 + 1,mid + 1,r);
        seg[id] = min(seg[id * 2],seg[id * 2 + 1]);
    }
}


void update(int id,int l,int r,int pos,int val){
    if(l == r) seg[id] = val;
    else{
        int mid = l + (r - l) / 2;
        if(pos <= mid) update(id * 2,l,mid,pos,val);
        else update(id * 2 + 1,mid + 1,r,pos,val);
        seg[id] = min(seg[id * 2],seg[id * 2 + 1]);
    }
}

//tra ve min trong [u-v]
int get(int id,int l,int r,int u,int v){
    if(v < l || u > r) return INF;
    if(u <= l && v >= r) return seg[id];
    int mid = l + (r - l) / 2;
    if(v <= mid) return get(id * 2,l,mid,u,v);
    else if(u > mid) return get(id * 2 + 1,mid + 1,r,u,v);
    return min(get(id * 2,l,mid,u,mid),get(id * 2 + 1,mid + 1,r,mid + 1,v));
}

void solve(){
    int n,q;cin >> n;
    a.resize(n + 1,0);
    FOR1(i,n) cin >> a[i];
    seg.resize(4 * n,0);
    build(1,1,n);
    cin >> q;
    FOR0(i,q){
        int type,a,b;cin >> type >> a >> b;
        if(type == 1) update(1,1,n,a,b);
        else cout << get(1,1,n,a,b) << endl;
    }
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve();
}
// https://codeforces.com/gym/464398/problem/A

/*
5
1 4 3 2 5
3
0 3 5
1 4 5
0 2 4*/
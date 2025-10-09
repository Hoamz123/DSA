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

//build ham tong doan con
void build(int id,int l,int r){
    if(l == r) {
        seg[id] = a[l];
        return;
    }
    else{
        int mid = l + (r - l) / 2;
        build(id * 2,l,mid);
        build(id * 2 + 1,mid + 1,r);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
}

void update(int id,int l,int r,int pos,int val){
    if(l == r) seg[id] = val;
    else{
        int mid = l + (r - l) / 2;
        if(pos <= mid) update(id * 2,l,mid,pos,val);
        else update(id * 2 + 1,mid + 1,r,pos,val);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
}

ll get(int id,int l,int r,int u,int v){
    if(v < l || u > r) return 0;
    if(u <= l && v >= r) return seg[id];
    int mid = l + (r - l) / 2;
    if(v <= mid) return get(id * 2,l,mid,u,v);
    else if(u > mid) return get(id * 2 + 1,mid + 1,r,u,v);
    return get(id * 2,l,mid,u,mid) + get(id * 2 + 1,mid + 1,r,mid + 1,v);
}

void solve(){
    int n,q;cin >> n >> q;
    a.resize(n + 1);
    seg.resize(4 * n);
    FOR1(i,n) cin >> a[i];
    build(1,1,n);
    FOR1(i,q){
        int t;cin >> t;
        if(t == 1){
            int x,v;cin >> x >> v;
            update(1,1,n,x,v);
        }
        else {
            int l,r;cin >> l >> r;
            cout << get(1,1,n,l,r) << endl;
        }
    }
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

//A and B
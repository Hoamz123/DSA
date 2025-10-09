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
vector<int> a;
vector<ll> seg;

void build(int id,int l,int r){
    if(l == r) seg[id] = a[l];
    else{
        int mid = (l + r) / 2;
        build(id * 2,l,mid);
        build(2 * id + 1,mid + 1,r);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
}

//range [u - v] -> sum
//O(log(n))
ll get(int id,int l,int r,int u,int v){
    if(v < l || u > r) return 0;
    if(u <= l && v >= r) return seg[id];
    int mid = (l + r) / 2;
    if(v <= mid) return get(id * 2,l,mid,u,v);
    if(u > mid) return get(id * 2 + 1,mid+1,r,u,v);
    return get(id * 2,l,mid,u,mid) + get(id * 2 + 1,mid + 1,r,mid + 1,v);
}

//update a[pos] = val
//O(log(n))
void update(int id,int l,int r,int pos,int val){
    if(l == r) seg[id] = val;
    else{
        int mid = (l + r) / 2;
        if(pos <= mid) update(id * 2,l,mid,pos,val);
        else update(id * 2 + 1,mid + 1,r,pos,val);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
}

// void solve(){
//     cin >> n;
//     FOR0(i,n) cin >> a[i];
//     seg.resize(4 * n,0);
//     build(1,0,n-1);
//     //sum [2-3]
//     cout << get(1,0,n-1,2,3) << endl;
//     //update a[2] = 10
//     update(1,0,n-1,2,10);
//     cout << get(1,0,n-1,2,3);
// }

void solve_(){
    int n,q;cin >> n >> q;
    a = vi(n+1,0);
    seg.resize(4 * n,0);
    build(1,1,n);
    FOR1(i,q){
        int type,x,y;cin >> type >> x >> y;
        if(type == 1) {
            update(1,1,n,x,y);
        }
        else{
            cout << get(1,1,n,x,y) << endl;
        }
    }
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve_();
    //acc
}
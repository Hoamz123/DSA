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
#define LNF 10000000000000001
#define ull unsigned long long
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'


//gia thiet cac phan tu tnrog mang deu > 0

/**
 * 1 tang cac truy van tu l den r mot c
 * 2 tra ve min trong dioan tu l den r
 */

struct SegmentTree{
    int n;
    vll a,minVal,lazy;

    SegmentTree(int _n,vll &_a){
        n = _n;
        a = _a;
        if(n > 0){
            minVal.assign(4 * n + 1,0);
            lazy.assign(4 * n + 1,0);
        }
    }

    void build(int i,int l,int r){
        if(l == r) minVal[i] = a[l];
        else{
            int m = (l + r) >> 1;
            build(i * 2,l,m);
            build(i * 2 + 1,m + 1,r);
            minVal[i] = min(minVal[i * 2],minVal[i * 2 + 1]);
        }
    }

    //tu thong tin o i chuyen de thong tin cua hai root con la i * 2 va i * 2 + 1
    void pushDown(int i){
        if(lazy[i] == 0) return;
        else{
            //khi tang tu l den r them c ->min cua no cung tang them c
            //day suong 2 note la tra va phai
            minVal[i * 2] += lazy[i];
            minVal[i * 2 + 1] += lazy[i];
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
            lazy[i] = 0;
        }
    }

    //update
    void update(int i,int l,int r,int u,int v,int c){
        if(l > r || u > v || r < u || v < l) return;
        if(u <= l && v >= r) {
            minVal[i] += c;
            lazy[i] += c;
            return;
        }
        pushDown(i);
        int m = (l + r) >> 1;
        update(i * 2,l,m,u,v,c);
        update(i * 2 + 1,m + 1,r,u,v,c);
        minVal[i] = min(minVal[i * 2],minVal[i * 2 + 1]);
    }

    //getMIN
    ll getMin(int i,int l,int r,int u,int v){
        if(l > r || u > v || r < u || v < l) return LNF;
        if(u <= l && v >= r) return minVal[i];
        pushDown(i);
        int m = (l + r) >> 1;
        ll L =  getMin(i * 2,l,m,u,v);
        ll R = getMin(i * 2 + 1,m + 1,r,u,v);
        return min(L,R);
    }
};

void solve(){
    int n,q;cin >> n >> q;
    vll a(n + 1);
    REP(i,1,n) cin >> a[i];
    SegmentTree tree(n,a);
    tree.build(1,1,n);
    REP(i,1,q){
        int t;cin >> t;
        if(t & 1){
            int l,r,c;cin >> l >> r >> c;
            tree.update(1,1,n,l,r,c);
        }
        else{
            int u,v;cin >> u >> v;
            cout << tree.getMin(1,1,n,u,v) << endl;
        }
    }
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve();
}
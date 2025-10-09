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
#define ull unsigned long long
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'

/**
 * moi thao tac se update : l r c : [l..r] += c;
 * thao tac getSum(l,r) = ?
 * sum[i] = tong cac phan tu trong vung quan ly cua nut i
 * khi update tong cua nut i se tang them c * (r - l + 1)
 */

struct SegmentTree{
    int n;
    vector<int> sum,lazy;

    SegmentTree(int _n){
        n = _n;
        if(n > 0){
            sum.assign(4 * n + 1,0);
            lazy.assign(4 * n + 1,0);
        }
    }
    //pushDown
    void pushDown(int i,int l,int r){
        if(lazy[i] == 0) return;
        int mid = (l + r) >> 1;
        sum[i * 2] += lazy[i] * (mid - l + 1);
        sum[i * 2 + 1] += lazy[i] * (r - mid);
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
        lazy[i] = 0;
    }

    void update(int i,int l,int r,int u,int v,int c){
        if(l > v || r < u || l > r || v < u) return;
        if(u <= l &&  v >= r){
            sum[i] += c * (r - l + 1);
            lazy[i] += c;
            return;
        }
        pushDown(i,l,r);
        int m = (l + r) >> 1;
        update(i * 2,l,m,u,v,c);
        update(i * 2 + 1,m + 1,r,u,v,c);
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }

    int getSum(int i,int l,int r,int u,int v){
        if(l > v || r < u || l > r || v < u) return 0;
        if(u <= l && v >= r) return sum[i];//u l r v
        pushDown(i,l,r);
        int m = (l + r) >> 1;
        int L = getSum(i * 2,l,m,u,v);
        int R = getSum(i * 2 + 1,m + 1,r,u,v);
        return L + R;
    }

    void update(int l,int r,int c){
        update(1,1,n,l,r,c);
    }

    int getSum(int l,int r){
        return getSum(1,1,n,l,r);
    }
};

void solve(){
    int n;cin >> n;
    SegmentTree seg(n);
    seg.update(2,5,3);
    FOR1(i,n) cout << seg.getSum(1,i) << ' ';
    cout << endl;
    seg.update(6,9,2);
    FOR1(i,n) cout << seg.getSum(1,i) << ' ';
    cout << endl;
    seg.update(1,7,5);
    FOR1(i,n) cout << seg.getSum(1,i) << ' ';
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    solve();
}
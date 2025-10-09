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
 * cho day a1 a2 a... an.Can thuc hien q thao tac thuoc hai dang:
 * 1 : update l r c gan a[i] += c voi moi i tu  l den r
 * 2 sum l r : tinh tong cua doan l-r
 * MOI nut luu 2 thong tin:
 * Loai 1 : sum[i] tong cac phan tu trong vung quan ly cua nut i
 * Loai 2 lazy
 * -> khi moi phan tu cua nut i [l..r] cung += c -> tong cua nut i se tang them c(r - l + 1)
 */

struct SegmentTree{
    vector<int> sum,lazy,a;
    int n;

    SegmentTree(int _n){
        n = _n;
        if(n > 0){
            sum.assign(4 * n + 1,0);
            lazy.assign(4 * n + 1,0);
        }
    }

    //neu mang ban dau khac khong
    void build_tree(int i,int l,int r){
        if(l == r) sum[i] = a[l];
        else{
            int m = (l + r) >> 1;
            build_tree(i * 2,l,m);
            build_tree(i * 2 + 1,m + 1,r);
            sum[i] = sum[i * 2] + sum[i * 2 + 1];
        }
    }

    void pushDown(int i,int l,int r){
        if(lazy[i] == 0) return;
        int m = (l + r) >> 1;
        sum[2 * i] += lazy[i] * (m - l + 1);
        sum[2 * i + 1] += lazy[i] * (r - m);
        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];
        lazy[i] = 0;
    }

    //xet nut i quan li doan l,r va danh co tv cap nhat tang [u,v] += c
    void update(int i,int l,int r,int u,int v,int c){
        if(l > v || r < u || l > r || v < u) return;

        if(u <= l && r <= v){
            sum[i] += (c * (r - l + 1));
            lazy[i] += c;
            return;
        }
        pushDown(i,l,r);
        int m = (l + r) >> 1;
        update(2 * i,l,m,u,v,c);
        update(2 * i + 1,m + 1,r,u,v,c);

        sum[i] = sum[i * 2] + sum[i * 2 + 1];//pushUP
    }

    //xet nut i quan ly doan l r can tinh tong doan u den v
    int getSum(int i,int l,int r,int u,int v){
        if(l > v || r < u || l > r || v < u) return 0;
        if(u <= l && r <= v) return sum[i];
        pushDown(i,l,r);
        int m = (l + r) >> 1;
        int L = getSum(2 * i,l,m,u,v);
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
    vector<int> a(n + 1);
    FOR1(i,n) a[i] = 1;//vi du
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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve();
}
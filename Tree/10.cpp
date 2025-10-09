#include <bits/stdc++.h>
using namespace std;
#define faster(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umi unordered_map<int, int>
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
 * Ví dụ 3: Cho dãy a1 a2 ... an. Cần thực hiện q thao tác thuộc hai dạng:
(1) UPDATE l r x y:
    Gán a[l] += x, a[l + 1] += x + y, a[l + 2] += x + 2 * y, ...,
    Gán a[r] += x + (r - l) * y
    Tổng quát: Gán a[i] += x + (i - l) * y với mọi i từ l đến r
    Tương đương với: a[i] += (x - l * y) + i * y
    -> pha ngoac : a[i] += (x - l*y) + i*y

(2) SUM l r: Tính tổng a[l] + a[l + 1] + ... + a[r]

Phan tich :
    -do thao tac yc tinh tong cac so trong doan [l,r],o moi nut cua seg ,ta can luu lai tong cac so trong cung quan ly cua no
    -voi moi nut i co vung ql l,r -> sum[i] = tong cac phan tu tu l den r

    -Do thao tac cap nhat tac dong nen 1 doan lien tiep ,ta phai luu lai thong tin lazy
    lazy[i] phai luu duoi dang pair,
    lazy[i] la mot pair<int,int> voi moi vt j trong lr ta can tang vi tri j them lazy[i].fi + lazy[i].se

    voi lazy[i].fi = (x - l*y) : Khong thay doi
    lazy[i].se = i * y : Thay doi theo index

    //Nhan xet neu mot nut i co vung quan ly la l r ma moi phan tu cua no cung chiu tac dong cua mot thao taccap nhat dang x,y -> ta co the tinh nhanh lai sum[i] = cach
    Nut i ql doan l,r
        a[l] += x + l * y;
        a[l + 1] += x + (l + 1) * y;
        ....
        a[r] += x + (r * y)

        -> Tong luong tang tren moi phan tu cua doan [l,r]
        sum[i] += (r - l + 1) * x + (tong cac so tu l den r) * y
        tong cac so tu l den r -> S(n) = (l + r) * (r - l + 1) / 2
    */

ll sumRange(int l,int r){
    return (l + r) * (r - l + 1) / 2;
}
struct SegmentTree{
    vector<ll> sum;
    vector<pii> lazy;
    int n;

    SegmentTree(int _n){
        n = _n;
        if (n > 0){
            sum.assign(4 * n + 1, 0);
            lazy.assign(4 * n + 1, make_pair(0,0));
        }
    }

    void pushDown(int i,int l,int r){
        if(lazy[i].first == 0 && lazy[i].second == 0) return;
        int m = (l + r) >> 1;
        sum[2 * i] += 1ll * (m - l + 1) * lazy[i].first + sumRange(l,m) * lazy[i].second;
        sum[i * 2 + 1] += 1ll * (r - m) * lazy[i].first + sumRange(m + 1,r) * lazy[i].second;
        //su dung tt loai 2 cua cha de cap nhat cho con
        for(int j = i * 2;j<=i * 2 + 1;j++){
            lazy[j].first += lazy[i].first;
            lazy[j].second += lazy[i].second;
        }
        lazy[i] = make_pair(0,0);//xoa thong tin lazy
    }

    void update(int i, int l, int r, int u, int v, int x,int y){
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v){
            sum[i] += 1ll * (r - l + 1) * x + sumRange(l,r) * y;
            lazy[i].first += x;
            lazy[i].second += y;
            return;
        }
        pushDown(i,l,r);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, x,y);
        update(2 * i + 1, m + 1, r, u, v, x,y);
        sum[i] = sum[i * 2] + sum[i * 2 + 1];//push up
    }

    ll getSum(int i, int l, int r, int u, int v){
        if (l > v || r < u || l > r || v < u) return 0;
        if (u <= l && r <= v) return sum[i];
        pushDown(i,l,r);
        int m = (l + r) >> 1;
        ll L = getSum(2 * i, l, m, u, v);
        ll R = getSum(i * 2 + 1, m + 1, r, u, v);
        return L+ R;
    }

    void update(int l, int r, int x,int y){
        update(1, 1, n, l, r, x - l * y,y);
    }

    int getSum(int l, int r){
        return getSum(1, 1, n, l, r);
    }
};

void solve(){
    int n;cin >> n;
    SegmentTree myit(n);
    myit.update(3,7,2,1);
    for(int i=1;i<=n;i++) cout << myit.getSum(i,i) << ' ';
    cout << endl;
    myit.update(2,5,3,6);
    for(int i=1;i<=n;i++) cout << myit.getSum(1,i) << ' ';
    cout << endl;
    myit.update(1,10,5,-2);
    for(int i=1;i<=n;i++) cout << myit.getSum(i,i) << ' ';
    cout << endl;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve();
}
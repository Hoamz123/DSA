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
 * cho hai day a1 a2 a3.. an can thuc hien q thao tac sau
 * 1) set l r c gan gia tri a[l] = a[l + 1] = a[l + 2] = c;(gan tat ca cac phan tu7 trong doan lr = gia tri c)
 * 2) Max l r tim gia tri lon nhat trong doan L R
 * moi nut luu thong tin;
 * loai 1) MaxVal[i] ; gia tri lon nhat cua nut i quan ly doan l r
 * loai 2) lazy[i] = gia tri dc gan cho ca doan(quy uoc lazy[i] = -1 khong co thao tac gan)
 *   //gia su c > 0
 */

 /**
  * khi moi vi tri trong 1 doan L R dc gan  = c -> maxVAL cua ca doan la C
  */

//code tra ve max cua 2 so
void maximize(int &a,int b){
    if(a < b) a = b;
}

struct SegmentTree{
    vector<int> maxVal,lazy;
    int n;

    SegmentTree(int _n){
        n = _n;
        if(n > 0){
            maxVal.assign(4 * n + 1,0);
            lazy.assign(4 * n + 1,0);
        }
    }

    void pushDown(int i){
        if(lazy[i] < 0) return;
        //duyet dung 2 con trai va phai cua nut i
        for(int j = 2 * i;j <= 2 * i + 1;j++){
            maxVal[j] = lazy[i];
            lazy[j] = lazy[i];
        }
        lazy[i] = -1;//xoa thong tin lazy o nut i
    }

    //xet nut i quan li doan l,r va danh co tv cap nhat tang [u,v] += c
    void update(int i,int l,int r,int u,int v,int c){
        if(l > v || r < u || l > r || v < u) return;

        if(u <= l && r <= v){
            maxVal[i] = c;
            lazy[i] = c;
            return;
        }
        pushDown(i);
        int m = (l + r) >> 1;
        update(2 * i,l,m,u,v,c);
        update(2 * i + 1,m + 1,r,u,v,c);
        maxVal[i] = max(maxVal[i * 2],maxVal[i * 2 + 1]);
    }

    //xet nut i quan ly doan l r can tinh tong doan u den v
    int getMax(int i,int l,int r,int u,int v){
        if(l > v || r < u || l > r || v < u) return 0;
        if(u <= l && r <= v) return maxVal[i];
        pushDown(i);
        int m = (l + r) >> 1;
        int L = getMax(2 * i,l,m,u,v);
        int R = getMax(i * 2 + 1,m + 1,r,u,v);
        return max(L,R);
    }

    void update(int l,int r,int c){
        update(1,1,n,l,r,c);
    }

    int getMax(int l,int r){
        return getMax(1,1,n,l,r);
    }
};

void solve(){
    int n;cin >> n;
    SegmentTree seg(n);
    seg.update(2,5,3);
    FOR1(i,n) cout << seg.getMax(i,i) << ' ';
    cout << endl;
    seg.update(6,9,2);
    FOR1(i,n) cout << seg.getMax(i,i) << ' ';
    cout << endl;
    seg.update(4,7,5);
    FOR1(i,n) cout << seg.getMax(i,i) << ' ';
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve();
}
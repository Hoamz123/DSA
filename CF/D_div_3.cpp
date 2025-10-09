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

//cao nhat gia tri nho nhat va nho thu 2 va so luong phan tu nho thu nhat
void updateMin(ll x,ll &m,ll &mSec,int &cnt_Min){
    if(x < m){
        mSec = m;
        m = x;
        cnt_Min = 1;//reset
    }
    else if(x == m) cnt_Min++;//them 1 phan tu nho nhat
    else if(x < mSec) mSec = x;
}

//ham cap nhat gia tjri lon nhat va lon thu nhi va so luong phan tu lon thu nhat

void updateMax(ll y,ll &M,ll &Msec,int &cnt_Max){
    if(y > M){
        Msec = M;
        M = y;
        cnt_Max = 1;///RESET
    }
    else if(y == M) cnt_Max++;
    else if(y > Msec) Msec = y;
}

//HAM TRA VE DIEN TICH HINH VUONG NHO NHAT toi thieu de chua n con quai vat

ll getArea(ll w,ll h,ll n){
    ll tmp = w * h;
    //neu hien tai da chua du n con quai vat
    if(tmp >= n) return tmp;

    //neu chua du -> 2 case
    //case 1: co dinh chieu cao (mo rong chieu rong)
    ll wNew = max(w,(n + h - 1) / h);//(N + h - 1) / h: chieu rong toi thieu de * voi w >= h
    ll area_1 = wNew * h;
    //case 2:co dinh chieu rong (mo rong chieu cao)
    ll hNew = max(h,(n + w - 1)  / w);
    ll area_2 = w * hNew;
    
    //lay case toi thieu
    return min(area_1,area_2);
}

void solve(){
    int n;cin >> n;
    vector<pii> xy;
    FOR0(i,n){
        int x,y;cin >> x >> y;
        xy.pb({x,y});
    }
    ll xMin = INF,yMin = INF;
    ll xMax = -INF,yMax = -INF;
    ll xMin_se = INF, yMin_se = INF;
    ll xMax_se = -INF, yMax_se = -INF;

    int cnt_x_Min = 0,cnt_x_Max = 0,cnt_y_Min = 0,cnt_y_Max = 0;

    //base case
    if(n == 1){
        cout << "1\n";return;
    }

    //cap nhat lon nhat nho nhat
    for(auto &[x,y] : xy){
        updateMin(x,xMin,xMin_se,cnt_x_Min);
        updateMax(x,xMax,xMax_se,cnt_x_Max);
        updateMax(y,yMax,yMax_se,cnt_y_Max);
        updateMin(y,yMin,yMin_se,cnt_y_Min);
    }
    //tinh gia tri hinh chu nhat ban dau (chua du n con quai vat) khi chua toi uu
    ll ans = getArea(xMax - xMin + 1,yMax - yMin + 1,n);

    //thu loai bo nhung con quai tren bien
    for(auto &[x,y] : xy){
        if(!(x == xMin || x == xMax || y == yMax || y == yMin)) continue;//bo qua
        ll newWeightMin = (x == xMin && cnt_x_Min == 1) ? xMin_se : xMin;
        ll newWeightMax = (x == xMax && cnt_x_Max == 1) ? xMax_se : xMax;
        ll newHeightMin = (y == yMin && cnt_y_Min == 1) ? yMin_se : yMin;
        ll newHeightMax = (y == yMax && cnt_y_Max == 1) ? yMax_se : yMax;

        ll tmp = getArea((newWeightMax - newWeightMin + 1),(newHeightMax - newHeightMin + 1),n);
        ans = min(ans,tmp);
    }
    cout << ans << endl;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
    // acc
    // https://codeforces.com/contest/2114/my
}
/*
7
3
1 1
1 2
2 1
5
1 1
2 6
6 4
3 3
8 2
4
1 1
1 1000000000
1000000000 1
1000000000 1000000000
1
1 1
5
1 2
4 2
4 3
3 1
3 2
3
1 1
2 5
2 2
4
4 3
3 1
4 4
1 2

*/
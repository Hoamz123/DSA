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

//voi thoi gian times thi moi ban lam duoc cho bao nhieu nguoi roi cong lai -> boi vi cac ban lam viec // va doc lap voi nhau
int f(const vi &T,ll times){
    int sum = 0;
    for(int i : T){
        sum += (times / i);
    }
    return sum;
}
//khong can biet chinh xac la bao nhieu thoi gian ma chi can uoc luong thoi gian it nhat la dc f(x) >= M

void solve(){
    int n,m;cin >> n >> m;
    vi T(n);
    FOR0(i,n) cin >> T[i];
    ll L = 1, R = 1e18;//R la truong hop xau nhat khi chi co 1 ban ma phai lam viec cho M nguoi voi M = 1e9 va 1 nguoi lam het 1e9s
    int res = 0;
    while(L <= R){
        ll mid = L + (R - L) / 2;
        int pp = f(T,mid);
        if(pp >= m){
            res = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << res;
}

//tinh so fibonaci thu n
//de quy co nho de tinh so fibonaci thu n
unordered_map<ll,ll> mp;
ll fibo(ll n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(mp[n]) return mp[n];
    mp[n] = fibo(n-1) + fibo(n-2);
    return mp[n];
}



int main(){
    faster();
    int t = 1;
    while(t--){
        cout << fibo(30);
    }
}
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

void _solve(){
    int n,k;cin >> n >> k;
    vi a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    int l = 0;
    int ans = 0;
    ll sum = 0;
    for(int r = 0;r < n;r++){
        sum += a[r];
        while(sum >= k){
            ans += n - r;//cho nay neu a[r] >= k  thi cho nay se cong voi n ma trong khi chi co 1 phan tu (toi da 1 day)
            sum -= a[l++];
        }
    }
    cout << ans;
    //9/10 test
}

void solvee(){
    int n,k;cin >> n >> k;
    vi a(n);
    FOR0(i,n) cin >> a[i];
    int l = 0,sum = 0,cnt = 0;
    FOR0(r,n){
        sum += a[r];
        while(sum >= k){
            sum -= a[l++];
        }
        cnt += (r - l + 1);//so day con ket thuc tai r ma < k
    }
    //dem tong so day con co the tao torng day
    ll total = 1ll * n * (n + 1) / 2;
    cout << total - cnt << endl;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solvee();
    }
}

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
//nho la [start,end) khong lay end
//va cac diem phu ko bat buoc phai lien tuc
void solve(){
    int n;cin >> n;
    vector<pii> v;
    FOR0(i,n){
        int s,e;cin >> s >> e;
        v.pb({s,e});
    }

    int ans = -INF;
    for(int i=0;i<n;i++){
        int tmp = 0;
        vi a(1001,0);
        for(int j=0;j<n;j++){
            if(i != j){
                for(int k = v[j].fi;k < v[j].se;k++){
                    a[k] = 1;
                }
            }
        }
        for(int i : a) tmp += i;
        ans = max(ans,tmp);
    }
    cout << ans;
}

int main(){
    faster();
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
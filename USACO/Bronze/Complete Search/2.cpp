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
//do khong yeu cau ve thu tu ma lai yeu cau lon day co nhieu nhat -< ta se sort nen detoi uu do dai day chon
void solve(){
    int n,k;cin >> n >> k;
    vi a(n);
    FOR0(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int res = 1;
    for(int i=0;i<n;i++){
        int cnt = 1;
        for(int j = i + 1;j<n;j++){
            if(abs(a[i] - a[j]) <= k) cnt++;
        }
        res = max(res,cnt);
    }
    cout << res;
}

int main(){
    faster();
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
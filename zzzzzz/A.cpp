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

void solve_C(){
    int n;cin >> n;
    vector<ull> a(n+1);
    FOR1(i,n) {
        cin >> a[i];
    }
    ull ans = INF * 1ll * 10000;
    FOR1(i,n){
        ull ai = a[i];
        int j = i;
        while(j + 1 <= n && a[j + 1] == a[i]) j++;
        ull tmp = ai * (i - 1 + n - j);
        ans = min(ans,tmp);
        i = j;
    }
    cout << ans << endl;
}


int main(){
    faster();
    int t;cin >> t;
    while(t--){
        solve_C();
    }
}
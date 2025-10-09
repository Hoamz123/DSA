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

void solve(){
    int n,k;cin >> n >> k;
    string s;cin >> s;
    int cnt_0 = 0,cnt_1 = 0;
    for(char c : s) cnt_1 += (c - '0');
    cnt_0 = n - cnt_1;
    int haft = n / 2;//so cap doi xung nhieu nhta
    for(int i=0;i<=k;i++){
        int j = k - i;
        int number_0 = 2 * i + (haft - k);
        int number_1 = 2 * j + (haft - k);
        if(cnt_0 >= number_0 && cnt_1 >= number_1){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
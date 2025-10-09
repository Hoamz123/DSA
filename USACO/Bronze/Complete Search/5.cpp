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

//nho doc ki dau bai

void solve() {
	int n, k; cin >> k >> n;
	int a[k + 1][n + 1];
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			a[i][x] = j;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			bool ok = true;
			for (int s = 1; s <= k; s++) {
				if (a[s][i] >= a[s][j]) {
					ok = false;
					break;
				}
			}
			if (ok) cnt++;
		}
	}
	cout << cnt;
}



int main(){
    faster();
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	int t = 1;
    while(t--){
        solve();
    }
}
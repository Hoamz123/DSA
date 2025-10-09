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

void reverseInGroups(vector<int> &a, int k) {
    // code here
    int n = (int)a.size();
    for(int i=0;i<n;i++){
        int l = i;
        int r = min(n - 1,l + k - 1);
        while(l <= r) swap(a[l++],a[r--]);
        i += (k - 1);
    }
}


void rotateArr(vector<int>& a, int d) {
    // code here
    int n = a.size();
    d = (d % n);
    vector<int> v;
    for(int i=d;i<n;i++){
        v.push_back(a[i]);
    }
    for(int i=0;i<d;i++){
        v.push_back(a[i]);
    }
    a = v;
    for(int i : a) cout << i << " ";
}


void solve(){
    int n;cin >> n;
    int k;cin >> k;
    vector<int> v(n,0);
    for(int i=0;i<n;i++) cin >> v[i];
    rotateArr(v,k);
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
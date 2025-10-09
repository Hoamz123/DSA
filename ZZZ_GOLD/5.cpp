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

vector<int> addOne(vector<int>& a) {
        // code here
        int n = (int)a.size();
        vector<int> v;
        int pad = 1;
        for(int i=n-1;i>=0;i--){
            int tmp = (a[i] + pad) % 10;
            v.push_back(tmp);
            if(tmp != 0){
                pad = 0;
            }
        }
        if(pad == 1) v.push_back(pad);
    reverse(v.begin(),v.end());  
    return v;  
}

int maximumProfit(vector<int> &p) {
    // code here
    int buy = p[0];
    int ans = -1e9;
    for(int i=1;i<(int)p.size();i++){
        if(buy < p[i]){
            ans = max(ans,p[i] - buy);
        }
        buy = min(p[i],buy);
    }
    return ans;
}

void solve(){
    vector<int> a = {7, 10, 1, 3, 6, 9, 2};
    cout << maximumProfit(a);
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
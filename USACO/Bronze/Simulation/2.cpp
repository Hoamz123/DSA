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
    vector<pii> ve(4);
    FOR1(i,3){
        int c,m;cin >> c >> m;
        ve[i] = {c,m};
    }

    int t = 100;
    while(t > 0){
        if(t > 0){
            //do tu 1 snag 2(1 lan)
            int w = min(ve[2].first,ve[2].second + ve[1].second);
            ve[1].second -= (w - ve[2].second);
            ve[2].second = w;
            t--;
        }
        if(t > 0){
            //do tu 2 snag 3
            int w = min(ve[3].first, ve[3].second + ve[2].second);
            ve[2].second -= (w - ve[3].second);
            ve[3].second = w;
            t--;
        }
        if(t > 0){
            //do tu 3 sang 1
            int w = min(ve[1].first, ve[1].second + ve[3].second);
            ve[3].second -= (w - ve[1].second);
            ve[1].second = w;
            t--;
        }
    }
    cout << ve[1].second << '\n' << ve[2].second << '\n' << ve[3].second;
}

int main(){
    faster();
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
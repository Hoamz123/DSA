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
    int n;cin >> n;
    vector<string> type(n+1);
    vector<pii> num(n+1);
    FOR1(i,n) cin >> type[i] >> num[i].fi >> num[i].se;

    int low = 0,high = INF;
    PER(i,n,1){
        if(type[i] == "none"){
            low = max(low,num[i].fi);
            high = min(high,num[i].se);
        }
        else if(type[i] == "on"){
            low -= num[i].se;
            high -= num[i].fi;
            low = max(0,low);
        }
        else if (type[i] == "off"){
            low += num[i].fi;
            high += num[i].se;
        }
    }
    cout << low << ' ' << high << endl;

    low = 0,high = INF;
    REP(i,1,n){
        if(type[i] == "none"){
            low = max(low,num[i].fi);
            high = min(high,num[i].se);
        }
        else if(type[i] == "on"){
            low += num[i].fi;
            high += num[i].se;
        }
        else if (type[i] == "off"){
            low -= num[i].se;
            high -= num[i].fi;
            low = max(0, low);
        }
    }
    cout << low << ' ' << high << endl;
}

int main(){
    faster();
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    // freopen("in.txt", "r", stdin);
    solve();
}
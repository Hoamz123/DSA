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

//acc
//https://codeforces.com/group/BegPu2Bixu/contest/625608/problem/A
bool check(pii a,pii b,pii c){
    double k1 = 1.0 * (b.second - a.second) / (b.first - a.first);
    double k2 = 1.0 * (c.second - a.second) / (c.first - a.first);
    return k1 == k2;//-> thang hang
}

void solve(){
    int n;cin >> n;
    vector<pii> v;
    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        v.pb({x,y});
    }
    ll total = n * (n - 1) * (n - 2) / 6;
    for(int i=0;i<n-2;i++){
        for(int j = i+1;j<n-1;j++){
            for(int k = j + 1;k<n;k++){
                if(check(v[i],v[j],v[k])) total--;
            }
        }
    }
    cout << total << endl;
}

int main(){
    faster();
    solve();
}
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

void solve(){
    int n;cin >> n;
    vector<pii> a(n);
    int Max = 0;
    FOR0(i,n){
        int s,t;cin >> s >> t;
        a[i] = {s,t};
        Max = max({Max,s,t});
    }
    vi diff(Max + 1,0);
    for(auto &[s,t] : a){
        diff[s]++;
        if(t < Max) diff[t + 1]--;
    }
    int x = 0,y = 0;//x la so den sang nhieu nhat tim dc
    //y la so thoi diem den sang nhieu nhat
    FOR1(i,Max) diff[i] += diff[i-1];

    FOR1(i,Max) cout << diff[i] << ' ';
    cout << endl;

    for(int i = 1;i<=Max;i++){
        if(diff[i] > x){
            y = 0;//reset
            x = diff[i];
        }
        if(diff[i] == x){
            y++;
        }
    }
    cout << x << ' ' << y;
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}
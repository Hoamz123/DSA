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


bool cmp(vi &a,vi &b){
    return a[0] < b[0];
}

void solve(){
    int n;cin >> n;//so ngay
    vector<vi> v(n);
    FOR0(i,n){
        int day,id,change;
        string name;
        cin >> day;cin >> name;cin >> change;
        if (name == "Mildred") id = 0;
        else if (name == "Elsie") id = 1;
        else id = 2;
        v[i] = {day,id,change};//v[i][0],v[i][1],v[i][2]
    }
    sort(v.begin(),v.end(),cmp);
    int res = 0;

    set<int> old;
    old.is(0);old.is(1);old.is(2);
    int a[3] = {7,7,7};
    FOR0(i,n){
        int id = v[i][1];
        int change = v[i][2];
        a[id] += change;
        int maxNow = *max_element(a,a + 3);
        set<int> dpNow;
        for(int i=0;i<3;i++){
            if(a[i] == maxNow){
                dpNow.is(i);
            }
        }
        if(old != dpNow) res++;
        old = dpNow;
    }
    cout << res;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // freopen("measurement.in", "r", stdin);
    // freopen("measurement.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
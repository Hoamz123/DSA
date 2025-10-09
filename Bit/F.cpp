#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'

int getFirstBitOn(int n) {
    return __builtin_ctz(n); // so bit 0 ngoai cung ben phai <=> index cua bit 1 dau tien
}

void solve() {
    int Sum, Limit;
    cin >> Sum >> Limit;

    vector<vi> indices(18);
    for (int i = 1; i <= Limit; ++i) {
        int pow2 = getFirstBitOn(i);
        indices[pow2].pb(i);///luu theo i tang dan
    }

    vi res;
    for (int k = 17; k >= 0; --k) {
        int power = 1 << k;
        while (power <= Sum && !indices[k].empty()) {
            res.pb(indices[k].back());//lay tu lon den nho
            indices[k].pop_back();
            Sum -= power;
        }
    }

    if (Sum != 0) {
        cout << -1 << endl;
        return;
    }

    cout << res.size() << endl;
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}


int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
        //acc
    }
    
}
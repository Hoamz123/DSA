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
    int x,y;cin >> x >> y;
    int tmp = x;
    int sumPath = 0;
    vi path = {1,-2,4,-8,16,-32,64,-128,256,-512,1024,-2048,4096};
    int ok = 1;
    for(int i : path){
        int yy = (x + i);
        REP(j,min(tmp,yy),max(tmp,yy)){
            if(j == y){
                ok = 0;
                break;
            }
        }
        if(ok == 0) sumPath += abs(tmp - y);
        else sumPath += (abs(tmp - yy));
        tmp = yy;
        if(ok == 0) {
            cout << sumPath;
            return;
        }
    }
}

int main(){
    faster();
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    solve();
}
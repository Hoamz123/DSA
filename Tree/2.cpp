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

vi a(nax,0);
int n;
vi BIT(nax,0);

//cap nhat a[pos] += val
void update(int pos,int val){
    while(pos <= n){
        BIT[pos] += val;
        pos += (pos & (-pos));
    }
}

int get(int pos){
    int sum = 0;
    // while(pos > 0){
    //     sum += BIT[pos];
    //     pos -= ((pos) & (-pos));
    // }
    for(;pos >= 1;pos &= pos - 1){
        sum += BIT[pos];
    }
    return sum;
}

void solve(){
    cin >> n;
    FOR1(i,n) cout << get(i) << ' ';
    cout << endl;
    update(4,19);
    FOR1(i, n)
        cout << get(i) << ' ';
    cout << endl;
    update(5,90);
    FOR1(i, n)
        cout << get(i) << ' ';
    cout << endl;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}
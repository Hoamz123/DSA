#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define len length
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'

int n,l,r,x;

bool ok(int sum,int m,int M){
    if(sum >= l && sum <= r && (M - m) >= x){
        return true;
    }
    return false;
}

void solve(){
    cin >> n >> l >> r >> x;
    vi a(n);
    FOR0(i,n) cin >> a[i];
    int cnt = 0;//dem so case thoa man
    int sum = 0;set<int> se;
    FOR1(mask,(1 << n)){//tuong duong voi 2^n
        sum = 0;se.clear();
        FOR0(j,n){
            //neu bit thu j la bit bat
            if((mask >> j) & 1){
                sum += a[j];
                se.insert(a[j]);
            }
        }
        //xong 1 cau hinh
        if((int)se.size() >= 2 && ok(sum,*se.begin(),*se.rbegin())) cnt++;
    }
    cout << cnt << endl;
    // cout << (10 >> 1);//chia doi lay nguyen duoi
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
        //acc
    }
    //acc
    
}
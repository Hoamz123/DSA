#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define mci map<char,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define sz size()
#define len length
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'


int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vi a(n);
        int ok = 0;
        int sum = 0;
        FOR0(i,n) {
            cin >> a[i];
            sum += a[i];
        }
        for(int i=0;i<n-1;i++){
            if(a[i] + a[i+1] == 0){
                cout << "YES" << endl;
                ok = 1;
                break;
            }
        }
        if(sum == n) {
            cout << "YES" << endl;
        }
        else if(ok != 1) cout << "NO" << endl;
    }
    //acc
}
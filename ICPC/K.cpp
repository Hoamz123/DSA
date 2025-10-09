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


void solve() {
    int n,a,b;cin >> n >> a >> b;
    string s;cin >> s;
    b = min(b,a + 1);

    //case 1(a == b)
    if(a == b){
        FOR0(i,n-a+1){
            if(s[i] == '0'){
                for(int j=i;j<i + a;j++){
                    if(s[j] =='0') s[j] = '1';
                    else s[j] = '0';
                }
            }
        }
        bool check = true;
        FOR0(i,n){
            if(s[i] != '1'){
                check = false;
                break;
            }
        }
        if(!check) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    //case 2(a == b + 1)
    else if(b == a + 1){
        bool check = true;
        if(n - a + 1 <= a){
            //trong doan [n-a+1->a] cac bit y/c giong nhau
            for(int i = n-a+1;i<a;i++){
                if(s[i] != s[i-1]){
                    check = false;
                    break;
                }
            }
        }
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


int main(){
    faster();
    int t;cin >> t;
    while(t--){
        solve();
        //acc
    }
    
}
/**
 * 3
7 3 4
0000000
3 3 3
101
3 2 3
101
 */
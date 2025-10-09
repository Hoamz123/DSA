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
// https://oj.vnoi.info/problem/icpc24_regional_f

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        string s;cin >> s;
        if(s == "fizz"){
            //chia het cho a but not b
            //chon a = 1
            cout << 1 << " ";
            for(int i=2;i<=1000001;i++){
                if(n % i != 0){
                    cout << i;
                    break;
                }
            }
        }
        else if(s == "buzz"){
            int a = -1;
            for(int i=2;i<=min(1000001,n);i++){
                if(n % i != 0){
                    a = i;
                    break;
                }
            }
            if(a == -1 || a == n){
                cout << -1 << " " << -1;
            }
            else if(a != n){
                cout << a << " " << n;
            }
        }
        else if(s == to_string(n)){
            //ko chia het cho ca hai
            int cnt = 0;
            for(int i=2;i<=1000001;i++){
                if(n % i != 0){
                    cout << i << " ";
                    cnt++;
                }
                if(cnt == 2) break;
            }
        }
        else if(s == "fizzbuzz"){
            //chia het cho ca hai
            if(n != 1){
                cout << 1 << " " << n;
            }
            else cout << -1 << " " << -1;
        }
        cout << endl;
    }
    //acc
}
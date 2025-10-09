#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000005
#define mod 1000000007
#define M -1000000001
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR(i,n) for(int i=0;i<=(n);i++)

int f[1001][1001];

int cat(int n,int m){
    if(n == m) return 0;
    if(f[n][m] != -1) return f[n][m];
    int &ans = f[n][m];//khi ans thay doi- > f[n][m] cx thay doi
    ans = mod;
    for(int i=1;i<m;i++) ans = min(ans,cat(n,i) + cat(n,m-i) + 1);
    for(int i=1;i<n;i++) ans = min(ans,cat(i,m) + cat(n-i,m) + 1);
    return ans;
}
int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n,m;cin >> n >> m;
    memset(f,-1,sizeof(f));
    cout << cat(n,m);
}
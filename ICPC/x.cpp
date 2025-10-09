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
#define sz size()
#define len length
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'

int n, m, p, q;

bool check(int i,int j){
    return i >= 1 && i <= n && j >= 1 && j <= m;//n hang m cot
}


int main(){
    faster();
    cin >> n >> m >> p >> q;
    int cnt = 0;
    if(check(p-1,q-1)) cnt++;
    if(check(p-1,q)) cnt++;
    if(check(p-1,q+1)) cnt++;
    if(check(p,q-1)) cnt++;
    if(check(p,q+1)) cnt++;
    if(check(p+1,q-1)) cnt++;
    if(check(p+1,q)) cnt++;
    if(check(p+1,q+1)) cnt++;
    cout << cnt;
    // acc
    // https://oj.vnoi.info/problem/icpc24_mt_g
}
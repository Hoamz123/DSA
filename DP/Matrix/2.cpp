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
const int MOD = 1000000007;

#define MATRIX_SIZE 101
struct Matrix {
    int m, n;
    long long d[MATRIX_SIZE][MATRIX_SIZE];
 
    Matrix(int _m = 0, int _n = 0) {
        m = _m; n = _n;
        memset(d, 0, sizeof d);
    }
 
    Matrix operator + (const Matrix &a) const {
        Matrix res(m, n);
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            res.d[i][j] = d[i][j] + a.d[i][j];
            if (res.d[i][j] >= MOD) res.d[i][j] -= MOD;
        }
        return res;
    }
 
    Matrix operator * (const Matrix &a) const {
        int x = m, y = n, z = a.n;
        Matrix res(x, z);
        for (int i = 0; i < x; i++) for (int j = 0; j < y; j++)
		for (int k = 0; k < z; k++) {
            	res.d[i][k] += 1LL * d[i][j] * a.d[j][k];
            	if (res.d[i][k] >= 1LL * MOD * MOD) res.d[i][k] -= 1LL * MOD * MOD;//toi uu (chi can O(n^2) phep mod)
        	}
        for (int i = 0; i < x; i++) for (int k = 0; k < z; k++) res.d[i][k] %= MOD;
 
        return res;
    }
 
    Matrix operator ^ (long long k) const {
        Matrix res(n, n);//khoi tao bien luu ket qua tra ve
        for (int i = 0; i < n; i++) res.d[i][i] = 1;
        Matrix mul = *this;
        while (k > 0) {
            if (k & 1) res = res * mul;
            mul = mul * mul;
            k >>= 1;
        }
        return res;
    }
};

// https://codeforces.com/contest/691/problem/E
void solve(){
    int n;ll m;cin >> n >> m;
    vector<ll> a(n);
    FOR0(i,n) cin >> a[i];
    Matrix trans(n,n);
    FOR0(i,n) FOR0(j,n){
        if(__builtin_popcountll(a[i] ^ a[j]) % 3 == 0){
            trans.d[i][j]++;
        }
    }
    Matrix res(1,n);
    FOR0(i,n) res.d[0][i] = 1;
    res = res * (trans ^ (m-1));

    ll sum = 0;
    FOR0(i,n) {
        sum = (sum + res.d[0][i]) % mod;
    }
    cout << sum << endl;
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}
/*
2
5 2
15 1 2 4 8
5 1
15 1 2 4 8

*/
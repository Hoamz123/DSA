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
#define ull unsigned long long
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'

void diffArray(vector<int>& a, vector<vector<int>>& opr) {
    // code here
    vector<int> diff((int)a.size(),0);
    for(int i=0;i<(int)opr.size();i++){
        int l = opr[i][0];
        int r = opr[i][1];
        int v = opr[i][2];
        diff[l] += v;
        if(r + 1 < (int)a.size()){
            diff[r + 1] -= v;
        }
    }

    for(int i=1;i<(int)a.size();i++){
        diff[i] += diff[i-1];
    }
    for(int i=0;i<(int)a.size();i++){
        a[i] += diff[i];
    }
}

void solve(){

    vector<int> a = {2, 3, 5, 6, 7};
    vector<vector<int>> o = {{2, 4, 2}, {3, 4, -1}};
    diffArray(a,o);

    // vector<vector<int>> arr = {{1, 2, 3, 4},
    //                            {5, 6, 7, 8},
    //                            {9, 10, 11, 12},
    //                            {13, 14, 15, 16}};

    // int m = arr.size();
    // int n = arr[0].size();
    // vector<vector<int>> pref(m,vector<int>(n,0));
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         pref[i][j] = arr[i][j];
    //         if(i > 0) pref[i][j] += pref[i-1][j];
    //         if(j > 0) pref[i][j] += pref[i][j-1];
    //         if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
    //     }
    // }
    // for(int i =0 ;i<m;i++){
    //     for(int j=0;j<n;j++) cout << pref[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << endl;
    // cout << pref[2][2] - pref[2][0] - pref[0][2] + pref[0][0];
}

void _solve(){
    int n;cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        _solve();
    }
}
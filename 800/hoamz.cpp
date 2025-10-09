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

int par[1000001];

int findRoot(int u){
    if(u == par[u]) return u;
    return par[u] = findRoot(par[u]);
}

bool Union(int a,int b){
    a = findRoot(a);
    b = findRoot(b);
    if(a != b){
        par[b] = a;
        return true;
    }
    return false;
}

int minCost(int n, vector<vector<int>>& edges, int k) {
    int com = n;
    for(int i=0;i<=n;i++){
        par[i] = i;
    }

    sort(edges.begin(),edges.end(),[](vector<int> &a,vector<int> &b){
        return a[2] <= b[2];
    });

    int ans = 0;
    for(auto it : edges){
        int u = it[0],v = it[1],w = it[2];
        if(com == k) break;
        if(Union(u,v)){
            ans = max(ans,w);
            com--;
        }
    }
    return ans;
    // acc
}

string processStr(string s){
    string rs = "";
    for(char c : s){
        if(c == '#') rs = rs + rs;
        else if(c == '%') {
            rs = string(rs.rbegin(),rs.rend());
        }
        else if(c == '*') rs.pop_back();
        else rs.push_back(c);
    }
    return rs;
    //acc
}

void swapp(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void solve(vector<int> &a){
    int sz = a.size();
    for(int i=0;i<sz- 1;i++){
        for(int j = i + 1;j<sz;j++){
            if(a[j] < a[i]){
                swapp(a[i],a[j]);
            }
        }
    }
}

int main(){
    faster();
    int a[9] = {0};
    for(int i=1;i<=8;i++){
        int x;cin >> x;
        a[x] = 1;
    }
    for(int i=1;i<=9;i++){
        if(a[i] == 0){
            cout << i << ' ';
        }
    }
}

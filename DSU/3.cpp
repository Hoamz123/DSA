#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000005
int n,q;
int a[nax],par[nax],sz[nax];
vector<map<int,int>> color;


void make_set(int u){
    par[u] = u;
    color[u][a[u]] = 1;//tan xuat xuat hien cua mau a[u] trong thanh phan lien thong chua dinh u khoi tao la 1
    sz[u] = 1;
}

int find_set(int a){
    if(a == par[a]) return a;
    return par[a] = find_set(par[a]);
}

void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        par[b] = a;
        
        //gop mau
        for(auto &[fi,se] : color[b]){
            color[a][fi] += se;
        }
        color[b].clear();
    }
}

//tan xuat mau c trong thanh phan lien thong chua u
int get(int u,int c){
    u = find_set(u);
    if(color[u].find(c) == color[u].end()) return 0;
    return color[u][c];
}

void solve(){
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
    color.resize(n + 1);
    for(int i=1;i<=n;i++){
        make_set(i);
    }
    while(q--){
        int t,x,y;cin >> t >> x >> y;
        if(t == 1) union_set(x,y);
        else cout << get(x,y) << endl;
    }
}

int main() {
    solve();
    return 0;
}

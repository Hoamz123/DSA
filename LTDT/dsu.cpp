//cau truc du lieu distjoin set

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> par(1001,0);
vector<int> sz(1001,0);

void init(){
    cin >> n;
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

//tim dinh lead cho tap hop chua dinh u
int find(int u){
    if(u == par[u]) return par[u];
    return par[u] = find(par[u]);//toi uu nen duong
}

bool Union(int a,int b){
    a = find(a);//dai dien dinh a
    b = find(b);//dai dien dinh b
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a,b);//toi uu size
    sz[a] += sz[b];
    par[b] = a;
    return true;
}

int main(){
    init();
    if(Union(5,6)){
        for(int i=1;i<=n;i++){
            cout << i << " " << par[i] << endl;
        }
    }
}
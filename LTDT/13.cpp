//do thi co huong
//xap xep topo neu co the di tu dinh A -> dinh B thi dinh A phai xuat hien trc dinh B

//cach 1:
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> p[1001];//danh sach ke
vector<int> vst(1001,0);
vector<int> topo;
int idx = 0;

void dfs(int u){
    vst[u] = 1;
    for(int v : p[u]){
        if(!vst[v]){
            dfs(v);
        }
    }
    //khi 1 dinh da duoc tham xong -> chay het vong for
    topo[n-1 - (idx++)] = u;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int x,y;cin >> x >> y;
        p[x].push_back(y);
    }
    topo = vector<int> (n,0);

    for(int i = 1;i<=n;i++){
        if(!vst[i]) dfs(i);
    }
    for(int x : topo) cout << x << " ";
}

#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v;
    int w;
};

int n,m;
vector<pair<int,int>> adj[101];//danh sach ke cua dinh u
vector<int> used(101,0);//1 : dinh nam trong MST; 0 dinh nam trong V
int parent[101],d[101];

void prim(int u){
    priority_queue< pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> > q;//min heap : trong so nho nhat dua nen dinh
    vector<edge> mst;//danh sach mst
    q.push({0,u});//bat dau tu dinh u bat ki -> gia dinh trong so = 0
    int ans = 0;//tong trong so
    while(!q.empty()){
        auto top = q.top();q.pop();//lay dinh co trong so nho nhat ra
        int x = top.second;
        int w = top.first;
        if(used[x]) continue;//neu dinh da nam trong MST roi thi next
        ans += w;//cong trong so vao ket qua
        used[x] = 1;//danh dau <-> dua dinh vao mst
        if(u != x){
            //neu dinh vua lay ma khac voi dinh luc bat dau chay thuat toan (dinh gia dinh)
            mst.push_back({x,parent[x],w});
        }
        //duyet danh sach ke cua dinh x
        for(auto it : adj[x]){
            int y = it.first;//dinh noi tu dinh x
            int w = it.second;//trong so cua canh (x - y)
            if(!used[y] && w < d[y]){
                //neu y chua duoc them vao mst
                d[y] = w;
                q.push({d[y],y});//muc dich la day trong so va dinh thoan man vao q
                parent[y] = x;//tu x co the den y -> cha cua y la x
            }
        }
    }
    //d[y]: luu trong so nho nhat cua canh gan voi dinh y
    cout << ans << endl;
}


int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) d[i] = 1e9;
    prim(1);
}
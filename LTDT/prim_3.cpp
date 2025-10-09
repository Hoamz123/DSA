//tim trong so cua cay khung nho nhat

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1001];
int n,m;
vector<int> used(1001,0);

struct edge {
    int u,v;
    int w;
};

void prim(int u){
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> q;//top la {w,y} : sao cho w la nho nhat -> tuc la w tang dan minHeap
    int res = 0;
    q.push({0,u});
    while(!q.empty()){
        auto top = q.top();q.pop();
        int dinh = top.second;
        int w = top.first;
        if(used[dinh]) continue;
        used[dinh] = 1;
        res += w;

        //duyet danh sach ke cua dinh
        for(auto it : adj[dinh]){
            int y = it.first;
            int w = it.second;
            if(!used[y]){
                q.push({w,y});
            }
        }
    }
    cout << res;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    prim(1);
}
/*
6 9
1 2 12
1 3 4
2 3 1
2 4 5
2 5 3
3 5 2
4 5 3
4 6 10
5 6 8
*/
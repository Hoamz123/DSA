//kiem tra line thong voi BFS

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[101];
vector<int> vst(101,0);
vector<int> par(101,-1);

int s,e;//idnh bat dau - ket thuc

bool bfs(int u){
    queue<int> que;
    que.push(u);
    vst[u] = 1;

    while(!que.empty()){
        int v = que.front();que.pop();
        for(int x : adj[v]){
            if(!vst[x]){
                que.push(x);
                vst[u] = 1;
                par[x] = v;
            }
            else if(x != par[v]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int x,y;cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans;
    for(int i = 1;i<=n;i++){
        if(!vst[i]){
            if(bfs(i)){
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
    return 0;
}
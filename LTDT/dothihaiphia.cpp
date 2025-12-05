//kiem tra do thi bat ky co phai do thi hai phai hay khong
/**
 * do thi hai phia la do thi -> hai tap roi nhau ma 2 phan tu bat ki trong 1 tap khong co duong di
 */

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<int> color(101,-1);

int n,m;

bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(int x : adj[v]){
            if(color[x] == -1){
                //chua duoc to mau
                color[x] = (color[v]) ? 0 : 1;
                q.push(x);
            }
            else{
                //da duoc to mau
                if(color[x] == color[v]) return false;
            }
        }
    }
    return true;
}

bool dfs(int u,int par){
    color[u] = 1 - color[par];
    for(int v : adj[u]){
        if(color[v] == -1){
            if(!dfs(v,u)) return false;//neu nhu co 1 nhanh false -> moi ket luan false (neu dfs(v,u) == true thi chua chac nhanh khac da true ma la false -> sai)
        }
        else if(color[v] == color[u]) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //BFS
    // int flag = 1;
    // for(int i = 1;i<=n;i++){
    //     if(color[i] == -1){
    //         if(!bfs(i)){
    //             cout << "NO" << endl;
    //             flag = 0;
    //             break;
    //         }
    //     }
    // }
    // if(flag) cout << "YES";

    int flag = 1;
    color[0] = 1;
    for(int i = 1;i<=n;i++){
        if(color[i] == -1){
            //chua duoc duywet
            if(!dfs(i,0)){
                flag = 0;
                cout << "NO" << endl;
                break;
            }
        }
    }
    if(flag) cout << "YES";
}

/*
6 5
2 1
2 3
3 4
5 4
1 6*/
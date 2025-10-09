//kiem tra chu trinh tren do thi co huong
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
vector<int> color(1001,0);

bool dfs(int u){
    color[u] = 1;
    for(int v : adj[u]){
        if(color[v] == 0){
            if(dfs(v)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2;//duyet xong
    return false;
}


//dung kahn -> loai dan dinh

int in[1001] = {0};

bool kahn(){
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        cnt++;
        for(int v : adj[u]){
            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }
    return cnt != n;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    // for(int i=1;i<=n;i++){
    //     if(dfs(i)){
    //         cout << "YES";
    //         return 0;
    //     }
    // }
    // cout << "NO";
    if(kahn()) cout << "YES";
    else cout << "NO";
}

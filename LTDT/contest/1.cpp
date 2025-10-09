//cho q truy van tra ve 1 neu co duong di tu s -> t ngc lai tra ve -1

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001];
vector<int> used(1001,0);
vector<int> d(1001,0);
int k = 0;

void bfs(int u){
    used[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int u = q.front();q.pop();
        d[u] = k;
        for(int v : adj[u]){
            if(!used[v]){
                used[v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    //O(n+m+q);
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;cin >> q;
    vector<pair<int,int>> tv;
    for(int i =0;i<q;i++){
        int s,t;cin >> s >> t;
        tv.push_back({s,t});
    }

    for(int i = 1;i<=n;i++){
        if(!used[i]){
            k++;
            bfs(i);
        }
    }

    for(auto &[s,t] : tv){
        if(d[s] == d[t]){
            cout << 1 << " ";
        }
        else cout << -1 << " ";
    }
}




//O(q(n+m))
// int main(){
//     cin >> n >> m;
//     for(int i = 0;i<m;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int q;cin >> q;
//     vector<pair<int,int>> tv;
//     for(int i = 0;i<q;i++){
//         int s,t;cin >> s >> t;
//         tv.push_back({s,t});
//     }
//     for(auto &[s,t] : tv){
//         bfs(s);
//         (used[t]) ? (cout << 1 << " ") : (cout << -1 << " ");
//         used = vector<int>(1001, 0);
//     }
//     //hoi yeu
// }
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll,ll>;
const int maxn = 200005;
const ll INF = 1e18;

int n, m, A, B;
vector<pii> adj[maxn];
vector<int> vst_(maxn, 0);
vector<ll> d(maxn, INF);

void bfs(int u){
    queue<int> q;
    q.push(u);
    vst_[u] = 1;

    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto &[v, w] : adj[x]){
            if(!vst_[v]){
                vst_[v] = 1;
                q.push(v);
            }
        }
    }
}

void dijkstra(int start){
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    d[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        auto [dist, u] = pq.top(); pq.pop();

        if(dist > d[u]) continue; // skip bản ghi cũ

        for(auto &[v, w] : adj[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    cin >> n >> m >> A >> B;

    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bfs(A);

    if(!vst_[B]){
        cout << -1 << endl;
        return 0;
    }

    dijkstra(A);

    if(d[B] == INF) cout << -1 << endl;
    else cout << d[B] << endl;

    return 0;
}

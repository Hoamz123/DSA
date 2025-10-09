#include<bits/stdc++.h>
using namespace std;

//truy vet duong di tu dinh s den dinh t

int n,m,s,t;
vector<int> adj[1001];
vector<int> used(1001,0);
vector<int> parent(1001,0);

void bfs(int u){
    used[u] = 1;
    queue<int> qe;
    qe.push(u);
    while(!qe.empty()){
        int u = qe.front();qe.pop();
        for(int v : adj[u]){
            if(!used[v]){
                used[v] = 1;
                qe.push(v);
                parent[v] = u;
            }
        }
    }
}

void dfs(int u){
    used[u] = 1;
    for(int v : adj[u]){
        if(!used[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}

int main(){
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(s);
    if(!used[t]) cout << "1OK";
    else{
        stack<int> st;
        while(t != s){
            st.push(t);
            t = parent[t];
        }
        st.push(s);
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }

}
/*
10 10 1 10
1 2
1 3
1 4
2 5
2 7
3 6
4 8
5 9
7 10
9 10*/
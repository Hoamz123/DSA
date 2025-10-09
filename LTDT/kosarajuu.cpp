#include<bits/stdc++.h>
using namespace std;

//thuat toan kosaraju de dem so thanh phan lien thong manh,hay do thi  co lien thong manh hay khong  O(2(V+E)) chay 2 lan thuat toan DFS

vector<int> adj[1001];//chay xuoi
vector<int> rAdj[1001];//chay nguoc
int n,m;
stack<int> st;
vector<int> used(1001,0);

void dfs(int u){
    used[u] = true;//danh dau da duyet qua
    //duyet danh sach ke cua dinh u
    for(int v : adj[u]){
        if(!used[v]){
            dfs(v);
        }
    }
    //chay den day -> het duong di -> luu dinh vao stack
    st.push(u);
}

void dfsR(int u){
    used[u] = true;
    cout << u << " ";
    for(int v : rAdj[u]){
        if(!used[v]){
            dfsR(v);
        }
    }
}

bool kosa(){
    used = vector<int>(1001,0);
    for(int i = 1;i<=n;i++){
        if(!used[i]) dfs(i);//muc dich duyet 1 lan de dua het tat ca cac dinh vao stack
    }
    int cnt = 0;
    used = vector<int>(1001, 0);
    while(!st.empty()){
        int u = st.top();st.pop();
        if(!used[u]){
            dfsR(u);
            cout << endl;
            cnt++;
        }
    }
    cout << cnt  << endl;
    return cnt == 1;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        rAdj[v].push_back(u);
    }
    if(kosa()) cout << "Yes" << endl;
    else cout << "No" << endl;
}
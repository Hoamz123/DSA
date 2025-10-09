
//canh cau la canh ma khi bo canh do di -> lam tang so thanh pha lien thogn

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<int> used;
int n,m;
vector<pair<int,int>> p;



//O(v+e)
void dfs(int u){
    used[u] = 1;
    for(int v : adj[u]){
        if(!used[v]){
            dfs(v);
        }
    }
}


//su dung thuat toan dfs de loang tu dinh u nhung bo qua canh x-y
void dfs2(int u,int x,int y){
    used[u] = 1;
    for(int v : adj[u]){
        if((v == x && u == y) || (v == y && u == x)) continue;
        if(!used[v]){
            dfs2(v,x,y);
        }
    }
}

void canhcau(){
    used = vector<int>(101,0);
    int tplt = 0;
    for(int i = 1;i<=n;i++){
        if(!used[i]){
            dfs(i);
            tplt++;
        }
    }
    int ans = 0;//so canh cau
    for(auto it : p){
        int u = it.first;int v = it.second;
        int tmp = 0;//dem so thanh phan lien thong khi bo qua canh u,v;
        used = vector<int> (101,0);
        for(int i = 1;i<=n;i++){
            if(!used[i]){
                dfs2(i,u,v);
                tmp++;
            }
        }
        if(tmp > tplt){
            cout << u << " " << v << endl;
            ans++;
        }
    }
    cout << ans;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        p.push_back({u,v});
    }

    canhcau();
    return 0;
}
/*
10 8
10 9
10 8
10 3
10 4
5 3
10 1
5 1
5 4

result : 10 9
         10 8
*/
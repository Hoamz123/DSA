

//dinh tru : la dinh ma khi bo dinh do ra khoi do thi -> lam tang so thanh phan lien thong

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<int> used;
int n,m;
vector<pair<int,int>> p;

void dfs(int u){
    used[u] = 1;
    for(int v : adj[u]){
        if(!used[v]){
            dfs(v);
        }
    }
}

void dinhtru(){
    used = vector<int>(101,0);
    int tplt = 0;//dem so thanh phan lien thong ban dau
    for(int i = 1;i<=n;i++){
        if(!used[i]){
            dfs(i);
            tplt++;
        }
    }

    int ans = 0;//dem so dinh tru
    for(int i = 1;i<=n;i++){
        used = vector<int>(101,0);
        used[i] = 1;// gia dinh bo qua dinh i
        int tmp = 0;//dem so thanh phan lien thong sau khi bo qua dinh i
        for(int j = 1;j<=n;j++){
            if(!used[j]){
                dfs(j);
                tmp++;
            }
        }
        if(tmp > tplt){
            cout << i << " ";
            ans++;
        }
    }
    cout << endl << ans;
}

/*
10 6
5 4
5 2
10 2
10 7
5 3
10 1


result : 2 5 10 -> 3 dinh tru
*/



int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dinhtru();
}
//kiem tra chu trinh tren do thi co huong su dung dfs

#include<bits/stdc++.h>
using namespace std;


int n,m;
vector<int> adj[101];
vector<int> color(101,0);
// 0 : chua duyet
// 1 : dang duyet
// 2 : da duyet xong

bool dfs(int u){
    color[u] = 1;
    for(int v : adj[u]){
        if(color[v] == 0){
            if(dfs(v)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2;//da duyet xong
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int x,y;cin >> x >> y;
        adj[x].push_back(y);
    }

    for(int i = 1;i<=n;i++){
        if(color[i] == 0){
            if(dfs(i)){
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
    return 0;
}

/*
7 7
1 2
1 5
2 3
4 2
3 6
6 7
7 3
*/
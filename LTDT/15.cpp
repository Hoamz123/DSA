///kiem tra chu trinh cua di thi su dung DFS

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[101];
vector<int> vst(101,0);


bool dfs(int u,int par){
    vst[u] = 1;//danh dau da duyet qua
    for(int v : adj[u]){
        if(!vst[v]){
            if(dfs(v,u)) return true;
        }
       //neu da tham roi
        else if(v != par) return true;//neu v khong phai cha truc tiep cua u -> ton tai canh nguoc -> co chu trinh
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

    if(dfs(1,0)) cout << "YES";
    else cout << "NO";

}

/*
7 6
1 2
2 3
2 4
3 6
6 7
7 3
*/
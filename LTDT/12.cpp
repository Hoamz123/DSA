#include<bits/stdc++.h>
using namespace std;

///kiem tra xem co di dc tu 'A' -> 'B" hay khong
//'o' la di dc,'x' la o cam

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int d[101][101] = {0};

int n,m,s,t,u,v;
//u,v la toa do cua B
//s,t la toa do cua 'A'
char a[101][101];

bool dfs(int i,int j){
    if(a[i][j] == 'B') return true;
    a[i][j] = 'x';//danh dau da di qua
    for(int k = 0;k<4;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 > 0 && j1 > 0 && i1 <= n && j1 <= m && a[i][j] != 'x'){
            if(dfs(i1,j1)) return true;
        }
    }
    return false;
}

void bfs(int i,int j){
    queue<pair<int,int>> que;
    que.push({i,j});
    a[i][j] = 'x';///danh dau da duyet qua
    d[i][j] = 0;//di tu no -> chinh no -> ko co buoc
    while(!que.empty()){
        pair<int,int> pai = que.front();que.pop();
        for(int k = 0;k<4;k++){
            int i1 = pai.first + dx[k];
            int j1 = pai.second + dy[k];
            if(i1 > 0 && j1 > 0 && i1 <= n && j1 <= m && a[i1][j1] != 'x'){
                d[i1][j1] = d[pai.first][pai.second] + 1;
                if(a[i1][j1] == 'B') return;
                que.push({i1,j1});
                a[i1][j1] = 'x';
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == 'A'){
                s = i;
                t = j;
            }
            if(a[i][j] == 'B'){
                u = i;
                v = j;
            }
        }
    }
    // if(bfs(s,t)) cout << "YES";
    // else cout << "NO";
    bfs(s,t);
    cout << d[u][v];
    return 0;
/*
6 6
Aooxoo
oxoooo
oxoooo
ooooxx
Boooxo
oooxxx
*/
}
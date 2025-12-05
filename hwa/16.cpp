#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

int n, m;
char grid[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct State {
    int x, y, hp, step;
    //toa do [x][y],noi co hp,va step
};

int bfs(pii s, pii d) {
    bool visited[105][105][4] = {0};
    queue<State> q;
    q.push({s.first, s.second, 3, 0});
    visited[s.first][s.second][3] = true;

    while (!q.empty()) {
        auto [x,y,hp,step] = q.front(); q.pop();

        //den duoc vi tri diem d thi tra ve ket qua
        if (x == d.first && y == d.second) return step;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;//ngoai mang

            int nhp = hp;
            if (grid[nx][ny] == '+') nhp--;
            if (nhp <= 0) continue;

            //neu vi tri [nx][ny] khi co nhp chua duoc di den thi di den
            if (!visited[nx][ny][nhp]) {
                visited[nx][ny][nhp] = true;
                q.push({nx, ny, nhp, step + 1});
            }
        }
    }
    return -1;
    //acc
}

void solve() {
    cin >> n >> m;
    pii s, d;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') s = {i, j};
            if (grid[i][j] == 'D') d = {i, j};
        }

    cout << bfs(s, d) << "\n";
}

int main() {
    faster();
    solve();
}

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> g;
int n, m, p;
bool vst[30000];

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    g.resize(n);

    // Đọc các cạnh
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Đánh dấu các đỉnh có bò và hàng xóm của nó là đã thăm (không thể đi qua)
    for (int i = 0; i < p; ++i)
    {
        int u;
        scanf("%d", &u);
        --u;
        vst[u] = true;
        for (int j = 0; j < (int)g[u].size(); ++j)
        {
            int neighbor = g[u][j];
            vst[neighbor] = true;
        }
    }

    // BFS từ đỉnh 0
    queue<int> qu;
    int res = n;
    if (!vst[0])
    {
        qu.push(0);
        vst[0] = true;
    }

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        --res;
        for (int i = 0; i < (int)g[u].size(); ++i)
        {
            int v = g[u][i];
            if (!vst[v])
            {
                vst[v] = true;
                qu.push(v);
            }
        }
    }

    printf("%d\n", res);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umi unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define ull unsigned long long
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};
#define endl '\n'

int n,m;//n hang ,m cot
int a[1001][1001];
int vst[1001][1001];
vector<pii> space;//vung co cac dinh cao bang nhau
int cnt = 0;//dem so luong doi

//loang den tat ca nhung o cao bang h lien ke
void dfs(int i,int j,int h){
    vst[i][j] = 1;
    space.pb({i,j});
    for(int k=0;k<8;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && vst[i1][j1] == 0 && a[i1][j1] == h){
            dfs(i1,j1,h);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> a[i][j];
    }    
    memset(vst,0,sizeof(vst));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vst[i][j] == 0){
                space.clear();

                dfs(i,j,a[i][j]);
                int h = a[i][j];
                bool isOK = true;

                for(auto p : space){
                    for(int k=0;k<8;k++){
                        int i1 = p.first + dx[k];
                        int j1 = p.second + dy[k];
                        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] > h){
                            isOK = false;
                            break;
                        }
                    }
                    if(isOK == false) break;
                }
                if(isOK) cnt++;
            }
        }
    }
    cout << cnt;
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}

/*
8 7
4 3 2 2 1 0 1
3 3 3 2 1 0 1
2 2 2 2 1 0 0
2 1 1 1 1 0 0
1 1 0 0 0 1 0
0 0 0 1 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0

*/


//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .'  \|     |// '.
//                 /  \|||  :  |||// \.
//                / _||||| -:- |||||- \.
//               |   |  \  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//            ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//           Phật phù hộ, không bao giờ BUG
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
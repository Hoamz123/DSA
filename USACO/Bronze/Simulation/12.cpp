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
#define nax 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define fi first
#define se second

void solve(){
    //x hang ,y cot
    int n;cin >> n;
    map<pii,int> mp;
    mp[{0,0}] = 0;//danh di qua o (1,1)
    int x = 0,y = 0;
    int t = 0;
    int ans = INF;
    for(int i=0;i<n;i++){
        char c;int st;cin >> c >> st;
        for(int j=0;j<st;j++){
            t++;
            if(c == 'N') x--;
            else if(c == 'S') x++;
            else if(c == 'E') y++;
            else y--;
            
            if(mp.find({x,y}) != mp.end()){
                ans = min(ans,t - mp[{x,y}]);
            }
            mp[{x,y}] = t;
        }
    }
    cout << ((ans != INF) ? ans : -1);
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}


/**
 * di tren luoi vo han
 * (x,y) la toa do tren luoi
 * di bac -> x--
 * di nam x++
 * di dong y++
 * di tay y--
 *
 *
 *
 * do thang cha nay cat cham nen la neu o {i,j} cat o thoi diem t
 * -> xau t + x thi co o o (i,j) lai moc tro lai
 * -> ma thang cha nay bao la no chua bao h gap 1 o da dc cat co trc do roi
 * -> nen khoang khac thoi gian giua lan dau di vao o (i,j) va lan sau di vao O(i,j) phai >= x
 * -> tong ket lai ta se lay gia tri x nho nhat
 */
/*
6
N 10
E 2
S 3
W 4
S 5
E 8
*/
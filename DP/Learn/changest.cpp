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

// https://www.spoj.com/HVT/problems/CHANGEST/

/**
 * Với một xâu ký tự S cho trước, ta có thể thực hiện các phép biến đổi sau:

- D: Xoá một ký tự của xâu S. Ký hiệu D i trong đó i là vị trí cần xóa

- I: Chèn trước vị trí t của xâu S một ký tự c nào đó. Ký hiệu I t c. Qui định thêm về vị trí chèn: nếu xâu S có độ dài k,
vị trí chèn là 1, 2, 3, ..., k+1, chèn ở vị trí k+1 có nghĩa là viết thêm vào cuối xâu S

- R: Thay ký tự thứ t của S bởi ký tự c nào đó. Ký hiệu R t c

Giả sử X và Y là hai xâu ký tự. Độ dài xâu X là n, độ dài xâu Y là m (0≤m,n≤100)

Hãy tìm một dãy gồm ít nhất các phép biến đổi biến xâu X thành xâu Y (số phép biến đổi ít nhất này gọi là khoảng cách giữa hai xâu)
 */

void solve(){
    string s,t;cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = "1" + s;
    t = "1" + t;
    vector<vi> dp(n+1,vi(m+1,0));//dp[i][j] la dso buoc tou thieu de i thanh j
    FOR1(i,n) dp[i][0] = i;//ta can i buoic de tu xau i thanh xau ""
    FOR1(i,m) dp[0][i] = i;//tuong tu ta can i buoc de tu xau trong thanh xau i
    FOR1(i,n) FOR1(j,m){
        if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1];
        else{
            dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1;
        }
    }
    cout << dp[n][m] << endl;

    int i = n,j = m;
    while(i > 0 || j > 0){
        if(i > 0 && j > 0 && s[i] == t[j]){
            --i; --j;
        }
        //thay the
        else if(i > 0 && j > 0 && dp[i][j] == dp[i-1][j-1] + 1){
           cout << "R " << i << " " << t[j] << endl;
            --i; --j;
        }
        //xoa
        else if(i > 0 && dp[i][j] == dp[i-1][j] + 1){
            cout << "D " << i << endl;
            --i;
        }
        //chen
        else if(j > 0 && dp[i][j] == dp[i][j-1] + 1){
            cout << "I " << i << " " << t[j] << endl;
            --j;
        }
    }
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}

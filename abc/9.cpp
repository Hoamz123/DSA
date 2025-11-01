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
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'

void ms(int a[],int n,int val){
    FOR0(i,n) a[i] = val;
}
void solve(){
    string s;
    int k;
    cin >> k >> s;
    int n = s.size();
    int a[n];//1 dai dien cho con ki tu//0 dai din cho ki tu do bi xoa
    ms(a,n,1);
    int l = 0,r = n - 1;//index danh tu o den - 1;
    map<char,int> freq;
    for(char i: s) freq[i]++;
    while(l < r && (r - l + 1) > 3 * k){// = k thi dung tai du
        int flag = 0;
        if(freq[s[l]] > k) {
            a[l] = 0;
            freq[s[l++]]--;
            flag = 1;//co su thay doi
        }
        if(freq[s[r]] > k) {
            a[r] = 0;
            freq[s[r--]]--;//giam tan xuat
            flag = 1;//co su thay doi
        }
        if(!flag) break;
    }
    string tmp;
    for(int i = 0;i<n;i++){
        if(a[i]) tmp.push_back(s[i]);
    }
    int cnt = 0;
    bool check = false;
    for(int i=0;i<(int)tmp.size();i++){
        if(freq[tmp[i]] > k) {
            cnt++;//them 1 lan bo ki tu o giua
            freq[tmp[i]]--;
        }
        else if(freq[tmp[i]] < k){
            check = true;//luc nay co 1 ki tu se khong du k lan xuat hien
            break;
        }
    }
    cout << endl;
    cout << ((check) ? -1 : cnt);
}


void code2(){
    int k;string s;
    cin >> k >> s;
    map<char,int> cnt;
    int j = 0,ans = 1e9;
    for(int i=0;i<(int)s.size();i++){
        cnt[s[i]]++;
        while(cnt[s[j]] > k){
            cnt[s[j++]]--;
        }

        if(cnt['S'] >= k && cnt['C'] >= k && cnt['V'] >= k){
            ans = min(ans,i - j + 1 - 3 * k);
        }
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
}

int main(){
    faster();
    code2();
}


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
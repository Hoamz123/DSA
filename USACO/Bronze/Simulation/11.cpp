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


set<set<char>> s[4];

void test(char a, char b, char c){
    set<char> se;
    se.is(a);
    se.is(b);
    se.is(c);
    s[(int)se.size()].is(se);
}

void solve1(){
    char a, b, c, d, e, f, g, h, k;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> k;
    test(a, b, c);
    test(d, e, f);
    test(g, h, k);
    test(a, d, g);
    test(b, e, h);
    test(c, f, k);
    test(a, e, k);
    test(c, e, g);
    cout << s[1].size() << endl
         << s[2].size();
}


void solve(){
    set<set<char>> se;
    set<char> tmp;
    vector<vector<char>> ve(3,vector<char>(3));
    for(int i=0;i<3;i++){
        set<char> s;
        for(int j=0;j<3;j++){
            char c;cin >> c;
            ve[i][j] = c;
            s.is(c);
            if(i == j) tmp.is(c);
        }
        se.is(s);
    }
    se.is(tmp);
    for(int i=0;i<3;i++){
        set<char> s;
        for(int j=0;j<3;j++){
            s.is(ve[j][i]);
        }
        se.is(s);
    }
    tmp.clear();
    tmp.is(ve[0][2]);
    tmp.is(ve[1][1]);
    tmp.is(ve[2][0]);
    se.is(tmp);
    int sg = 0;
    int team = 0;
    for(auto it : se){
        if((int)it.size() == 1) sg++;
        else if((int)it.size() == 2) team++;
    }
    cout << sg << endl << team;
}

int main(){
    faster();
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    solve();
}
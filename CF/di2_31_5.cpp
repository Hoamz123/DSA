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

void solve_A(){
    int a,b,c,d;cin >> a >> b >> c >> d;
    a = min(a,c);
    b = min(b,d);
    if(a < b) cout << "Flower\n";
    else cout << "Gellyfish\n";
}

int gcd_(int a,int b){
    while(b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void solve_C(){
    int n;cin >> n;
    vector<int> a(n);
    unordered_map<int,int> mp;
    queue<int> q;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]] = 0;//da co ko can tao
        q.push(a[i]);
    }
    int cnt = 0;
    int g = a[0];
    for(int i=1;i<n;i++){
        g = gcd_(g,a[i]);
    }
    
    for(int i=0;i<n;i++){
        cnt += (a[i] == g);
    }
    
    if(cnt > 0){
        cout << n - cnt << endl;
        return;
    }
    
    while(!q.empty()){
        int top = q.front();q.pop();
        for(int x : a){
            int d = gcd_(x,top);
            if(mp.find(d) == mp.end()){
                mp[d] = mp[top] + 1;
                q.push(d);
            }
            //ngat luon n co the
            if(d == g){
                cout << mp[g] + n - 1 << endl;
                return;
            }
        }
    }
}

int main(){
    faster();
    int t;cin >> t;
    while(t--){
        solve_C();
    }
    //acc
}
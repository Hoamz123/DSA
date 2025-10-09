#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'

void solve() {
    int t1,s1,t2,s2;cin >> t1 >> s1 >> t2 >> s2;
    double tgSenDendich1 = 100.0 / (t1 + s1);
    double tgSenDiHetRua1 = 10.0 / s1;
    double time1=0;
    if(tgSenDendich1 <= tgSenDiHetRua1){
        time1 = tgSenDendich1;
    }
    else{
        time1 = tgSenDiHetRua1 + (100.0 - tgSenDiHetRua1*(t1+s1))/ t1;
    }

    double tgSenDendich2 = 100.0 / (t2 + s2);
    double tgSenDiHetRua2 = 10.0 / s2;
    double time2=0;
    if(tgSenDendich2 <= tgSenDiHetRua2){
        time2 = tgSenDendich2;
    }
    else{
        time2 = tgSenDiHetRua2 + (100.0 - tgSenDiHetRua2*(t2+s2))/ t2;
    }

    if (fabs(time1 - time2) < -INF) cout << "Draw\n";
    else if (time1 < time2) cout << "Megumin\n";
    else cout << "Yunyun\n";
    //acc
}


int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

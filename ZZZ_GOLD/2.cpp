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

bool cmd(pair<int,int> &a,pair<int,int> &b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second; 
}

void jobSequencing(vector<int> &d,vector<int> &p){
    vector<pair<int,int>> mp;
    for(int i=0;i<(int)d.size();i++){
        mp.push_back({d[i],p[i]});
    }
    sort(mp.begin(),mp.end(),cmd);
    priority_queue<int,vector<int>,greater<int>> q;
    for(auto &[dealine,profit] : mp){
        q.push(profit);
        if((int)q.size() > dealine){
            q.pop();
        }
    }
    int res = 0;
    int cnt = q.size();
    while((int)q.size() != 0){
        res += q.top();
        q.pop();
    }
    cout << cnt << ' ' << res << endl;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector<int> start = {4, 1 ,1 ,1};
    vector<int> end = {20 ,10 ,40 ,30};
    jobSequencing(start,end);
}
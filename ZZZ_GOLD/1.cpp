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

int _min(int a,int b,int c){
    int x = min(a,b);
    return min(x,c);
}

void solve(){
    int n;cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> pre(n,0),res(n,0);
    pre[n-1] = a[n-1];
    res[n-1] = pre[n-1];
    for(int i=n-2;i>-1;i--){
        pre[i] = min(a[i],a[i] + pre[i+1]);
        res[i] = min(pre[i],res[i+1]);
    }
    for(int i=0;i<n;i++) cout << res[i] << " ";
    cout << endl;
}


void maxMeetings(vector<int>& start, vector<int>& end) {
    // Your code here
    int n =  start.size();
    int cnt = 1;
    vector<pair<int,int>> meets;
    for(int i=0;i<n;i++){
        meets.push_back({end[i],start[i]});
    }

    sort(meets.begin(),meets.end());
    int en = meets[0].first;
    for(int i=1;i<n;i++){
        if(meets[i].second > en){
            cnt++;
            en = meets[i].first;
        }
    }
    cout << cnt;
}

// bool cmd(pair<int,int> &a,pair<int,int> &b){
//     if(a.first != b.first) return a.first > b.first;
//     return a.second > b.second;
// }

// void jobSequencing(vector<int> &deadline, vector<int> &profit) {
//     // code here
//     vector<pair<int,int>> mp;
//     map<int,int> count;
//     for(int i=0;i<(int)deadline.size();i++){
//         mp.push_back({deadline[i],profit[i]});
//         count[deadline[i]] = deadline[i];
//     }  
//     sort(mp.begin(),mp.end(),cmd);
//     int res = 0;
//     int cnt = 0;
//     int pivot = mp[0].first;
//     int tmp = pivot;
//     cout << endl;
//     priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> que;
//     for(auto &[fi,se] : mp){
//         if(fi <= tmp && cnt + 1 <= pivot && count[fi] - 1 != -1){
//             cout << fi << ' ' << se << endl;
//             cnt++;
//             tmp = fi;
//             count[fi]--;
//             que.push({fi,se});
//         }
//         else{
//             auto &[fir,sec] = que.top();
//             if(se > sec){
//                 que.pop();
//                 que.push({fi,se});
//                 count[fi]--;
//                 count[fir]++;
//             }
//         }
//     }
//     while(!que.empty()){
//         auto &[f,s] = que.top();que.pop();
//         res += s;
//     }
//     cout << cnt << " " << res << endl;
// }



int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector<int> start = {9, 8, 7, 6 ,6, 2 ,4 ,8 ,3 ,4 ,4};
    vector<int> end = {469 ,399, 64, 326, 331, 190 ,214, 337 ,87 ,425, 23};
    _jobSequencing(start,end);
}
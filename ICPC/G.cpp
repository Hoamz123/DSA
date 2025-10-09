#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define sz size()
#define len length
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'

pii findMax(vi &a){
    int max1 = -INF,max2 = -INF;
    int n = a.size();
    FOR0(i,n){
        if(a[i] > max1){
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2){
            max2 = a[i];
        }
    }
    return {max1,max2};
}

pii findMin(vi &a){
    int min1 = INF,min2 = INF;
    int n =  a.size();
    FOR0(i,n){
        if(a[i] < min1){
            min2 = min1;
            min1 = a[i];
        }
        else if(a[i] < min2) min2 = a[i];
    }
    return {min1,min2};
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vi a(n);
        FOR0(i,n) cin >> a[i];
        pii pMax = findMax(a);int max1 = pMax.first;int max2 = pMax.second;
        pii pMin = findMin(a);int min1 = pMin.first;int min2 = pMin.second;
        int res = INF;
        FOR0(i,n){
            //neu nhu bo a[i];
            int tmp1 = 0,tmp2 = 0;
            tmp1 = (a[i] == max1) ? max2 : max1;
            tmp2 = (a[i] == min1) ? min2 : min1;
            res = min(res,tmp1 - tmp2);
        }
        cout << res << endl;
    }
}
//region
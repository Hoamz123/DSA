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

/*
bai yeu cau tim so cap (i,j,k) i < j < 
de a[i],a[j],a[k] tao thanh tam giac
nen chi can i j k doi 1 khac nhau la dc
sort mang a,tinh tong a[i] + aa[j] = sum
tim vi tri cua phan tu nho nhat >= sum
khi do a[k] se nam trong doan tu [j+1,pos - 1]
-> cong vao gia tri tra ve so luong phan tu trong doan do deu thoa man
*/

void solve(){
    int n;cin >> n;
    vll a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j = i + 1;j<n;j++){
            ll tmp = a[i] + a[j];
            int pos = lower_bound(a.begin(),a.end(),tmp) - a.begin();
            cnt += (pos - j - 1);
        }
    }
    cout << cnt;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}

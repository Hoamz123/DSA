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

// //accepted
// void solve(){
//     ll a,b; cin >> a >> b;
//     if(a > b) swap(a,b);
//     ll k = 0;
//     while(k * (k + 1) < 2 * (b - a)){
//         k++;
//     }
//     ll d = a + k * (k + 1) / 2 - b;
//     if(!(d % 2)){
//         cout << k << endl;
//     }
//     else{
//         //d le -> tim cach dua d ve chan = viec lam them 1 so thao tac nua
//         if((k + 1) % 2){
//             cout << k + 1 << endl;
//         }
//         else{
//             cout << k + 2 << endl;
//         }
//     }
// }


void push(char x,char a[],int &n){
    a[n] = x;
    n++;
}

char pop(char a[],int &n){
    n--;
    return a[n];
}

char top(char a[],int n){
    return a[n - 1];
}


int temp(char c,int top1,int top2){
    if(c == '-') return (top2 - top1);
    else if(c == '+') return (top2 + top1);
    else if(c == '/') return (top2 / top1);
    return (top1 * top2);
}

int re(string s){
    stack<int> st;
    for(int i=0;i<(int)s.size();i+=2){
        if(isdigit(s[i])) st.push(s[i] - '0');
        else{
            if((int)st.size() >= 2){
                int top1 = st.top();st.pop();
                int top2 = st.top();st.pop();
                st.push(temp(s[i],top1,top2));
            }   
        }
    }
    return st.top();
}


void solve(){
    string s; cin >> s;
    int n = 0;
    char a[10001];
    string result = "";

    for(int i = 0; i < (int)s.size(); i++){
        if(isdigit(s[i])){
            result.push_back(s[i]);
            result.push_back(' ');
        }
        else{
            if(s[i] == '(') push(s[i],a,n);
            else if(s[i] == '*' || s[i] == '/') push(s[i],a,n);
            else if(s[i] == '+' || s[i] == '-'){
                while(n > 0 && (top(a,n) == '*' || top(a,n) == '/')){
                    result.push_back(pop(a,n));
                    result.push_back(' ');
                }
                push(s[i],a,n);
            }
            else if(s[i] == ')'){
                while(n > 0 && top(a,n) != '('){
                    result.push_back(pop(a,n));
                    result.push_back(' ');
                }
                if(n > 0) pop(a,n);//loai bo '('
            }
        }
    }

    while(n > 0){
        if(n != 1){
            result.push_back(pop(a,n));
            result.push_back(' ');
        }
        else result.push_back(pop(a,n));
    }
    cout << result << endl;
    cout << re(result) << endl;
}


int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve();
}
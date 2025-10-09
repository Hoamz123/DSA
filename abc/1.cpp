#include <bits/stdc++.h>
using namespace std;
#define faster()                      \
    {                                 \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);                   \
        cout.tie(0);                  \
    }
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umi unordered_map<int, int>
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

// ngay 1 quay tro lai leetcode
// easy
int findClosest(int x, int y, int z)
{
    int a = abs(x - z);
    int b = abs(y - z);
    if (a < b)
        return 1;
    else if (a > b)
        return 2;
    return 0;
}

// ngay 2 quay lai leetcode
// 150
int temp(char c, int top1, int top2)
{
    if (c == '-')
        return (top2 - top1);
    else if (c == '+')
        return (top2 + top1);
    else if (c == '/')
        return (top2 / top1);
    return (top1 * top2);
}

int num(string s)
{
    int am = 1;
    if (s[0] == '-')
    {
        am = -1;
        s = s.substr(1);
    }
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        res = (res * 10 + s[i] - '0');
    }
    return res * am;
}

bool check(string s)
{
    return s != "-" && s != "+" && s != "/" && s != "*";
}
int evalRPN(vector<string> &s)
{
    stack<int> st;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (check(s[i]))
            st.push(num(s[i]));
        else
        {
            if ((int)st.size() >= 2)
            {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(temp(s[i][0], top1, top2));
            }
        }
    }
    return st.top();
}


void solve()
{
    cout << findClosest(2, 5, 6);
}

int main()
{
    faster();
    solve();
}
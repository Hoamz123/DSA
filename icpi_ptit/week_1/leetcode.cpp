#include <bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}       

bool check(char c) {
    return c >= '0' && c <= '9';
}

int temp(char c, int top1, int top2) {
    if (c == '-') return (top2 - top1);
    else if (c == '+') return (top2 + top1);
    else if (c == '/') return (top2 / top1);
    return (top1 * top2);
}

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}
string res(string s) {
    stack<char> st;
    string rs = "";
    for (int i = 0; i < (int)s.size(); i++) {
        if (check(s[i])) {
            int x = 0;
            while (i < (int)s.size() && check(s[i])) {
                x = x * 10 + (s[i] - '0');
                i++;
            }
            rs += to_string(x);
            rs.push_back(' ');
            i--;
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                rs.push_back(st.top());
                rs.push_back(' ');
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            if (s[i] == '-'
                 && (i == 0 || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/')) {
                int j = i + 1;
                int x = 0;
                while (j < (int)s.size() && check(s[j])) {
                    x = x * 10 + (s[j] - '0');
                    j++;
                }
                rs += to_string(-x);
                rs.push_back(' ');
                i = j - 1;
            } else {
                while (!st.empty() && priority(st.top()) >= priority(s[i])) {
                    rs.push_back(st.top());
                    rs.push_back(' ');
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while (!st.empty()) {
        rs.push_back(st.top());
        rs.push_back(' ');
        st.pop();
    }
    return rs;
}

int _toInt(string s) {
    int x = 0, sign = 1, i = 0;
    if (s[0] == '-') { sign = -1; i = 1; }
    for (; i < (int)s.size(); i++) {
        x = (x * 10) + (s[i] - '0');
    }
    return sign * x;
}

int calculate(string s) {
    string ss = "";
    for (char c : s) if (c != ' ') ss.push_back(c);
    s = ss;
    int am = 1;
    if((int)s.size() >= 2 && s[0] == '-' && s[1] == '('){
        am = -1;
        s = s.substr(1);
    }
    s = res(s);
    stringstream sss(s);
    vector<string> ve;
    string tmp;
    while (sss >> tmp) ve.push_back(tmp);

    stack<int> st;
    for (string &tok : ve) {
        if (priority(tok[0]) >= 1 && tok.size() == 1) {
            int top1 = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            int val = temp(tok[0], top1, top2);
            st.push(val);
        } else {
            st.push(_toInt(tok));
        }
    }
    return st.top() * am;
}

int main() {
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << calculate("24 - 1 + 2") << endl; 
    cout << calculate("-(1-( -2))") << endl; 
    cout << calculate("-2+3*4") << endl;
}

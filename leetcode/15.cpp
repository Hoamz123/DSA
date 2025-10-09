#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, -1, 2};
    int k = 3;
    int n = a.size();
    int res = n + 1;

    // prefix[0] = 0
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    deque<int> dq;
    for (int i = 0; i <= n; ++i) {
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            res = min(res, i - dq.front());
            dq.pop_front();
        }

        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    
    if (res <= n)
        cout << res;
    else
        cout << -1; // không tìm được đoạn con thoả mãn
}

#include <iostream>
using namespace std;

void solve() {
    int n, m, p, q_val;
    cin >> n >> m >> p >> q_val;

    int num_full_blocks = n / p;
    int remainder_len = n % p;

    if (remainder_len == 0) {
        if (m == num_full_blocks * q_val) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;
    while (num_test_cases--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);

    // Nhập mảng
    for (int i = 1; i <= n; i++) cin >> A[i];

    // Bước 1: Lưu vị trí xuất hiện của mỗi giá trị
    unordered_map<int, vector<int>> pos;
    pos.reserve(n * 2); // tránh rehash, tối ưu tốc độ
    //chi cap phat bo nho khong phai kich co
    for (int i = 1; i <= n; i++) {
        pos[A[i]].push_back(i);
    }

    // Bước 2: Trả lời q truy vấn
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;

        if (pos.find(x) == pos.end()) {
            cout << 0 << "\n";
            continue;
        }

        const vector<int>& v = pos[x];
        // Tìm số chỉ số nằm trong [l, r]
        int left = lower_bound(v.begin(), v.end(), l) - v.begin();//chi so cua phan tu nho nhat >= l
        int right = upper_bound(v.begin(), v.end(), r) - v.begin();//chi so cua phan tu nho nhat > r
        cout << (right - left) << "\n";
    }

    return 0;
}

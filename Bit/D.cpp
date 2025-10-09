void solve() {
    int n;
    int  k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int res = 0;

    // Duyệt từng bit từ cao xuống
    for (int bit = 30; bit >= 0; --bit) {
        int cnt = 0;
        for (int x : a) {
            if (((x >> bit) & 1) == 0)
                cnt++;
        }
        if (cnt <= k) {
            res |= (1 << bit);
            k -= cnt;
            // Giả sử bật bit này trong tất cả a[i] thiếu
            for (int i = 0; i < n; ++i)
                a[i] |= (1 << bit);
        }
    }
        cout << res << "\n";
}
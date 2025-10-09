#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);  // d: sự thay đổi độ cao tại mỗi bước (0, 1 hoặc -1 nghĩa là chưa biết)
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    
    vector<int> obstacle_min_height(n);
    vector<int> obstacle_max_height(n);
    for (int i = 0; i < n; ++i) {
        cin >> obstacle_min_height[i] >> obstacle_max_height[i];
    }

    // Khoảng giá trị chiều cao có thể có tại vị trí i
    vector<int> min_height_possible(n + 1);
    vector<int> max_height_possible(n + 1);

    min_height_possible[0] = 0;  // ban đầu chiều cao bằng 0
    max_height_possible[0] = 0;

    // Duyệt tiến để tính khoảng giá trị chiều cao khả thi tại mỗi bước
    for (int i = 0; i < n; ++i) {
        int prev_min = min_height_possible[i];
        int prev_max = max_height_possible[i];

        int obstacle_l = obstacle_min_height[i];
        int obstacle_r = obstacle_max_height[i];
        
        int candidate_min, candidate_max;

        if (d[i] == 0) {
            // Không tăng chiều cao
            candidate_min = prev_min;
            candidate_max = prev_max;
        } else if (d[i] == 1) {
            // Tăng chiều cao 1 đơn vị
            candidate_min = prev_min + 1;
            candidate_max = prev_max + 1;
        } else {
            // d[i] == -1, chưa biết, có thể 0 hoặc 1 => khoảng từ prev_min đến prev_max+1
            candidate_min = prev_min;
            candidate_max = prev_max + 1;
        }
        
        // Cập nhật khoảng khả thi phải nằm trong khoảng chướng ngại vật
        min_height_possible[i+1] = max(candidate_min, obstacle_l);
        max_height_possible[i+1] = min(candidate_max, obstacle_r);

        // Nếu không tồn tại khoảng hợp lệ => in -1 và kết thúc
        if (min_height_possible[i+1] > max_height_possible[i+1]) {
            cout << -1 << "\n";
            return;
        }
    }

    // Mảng lưu khoảng chiều cao hợp lệ khi duyệt ngược từ cuối về đầu
    vector<int> final_min_height(n + 1);
    vector<int> final_max_height(n + 1);

    final_min_height[n] = min_height_possible[n];
    final_max_height[n] = max_height_possible[n];

    // Duyệt ngược để tinh chỉnh khoảng giá trị chiều cao khả thi dựa trên ràng buộc từ bước sau
    for (int i = n - 1; i >= 0; --i) {
        int next_min = final_min_height[i+1];
        int next_max = final_max_height[i+1];
        
        int required_min, required_max;

        if (d[i] == 0) {
            required_min = next_min;
            required_max = next_max;
        } else if (d[i] == 1) {
            // Vì chiều cao tăng 1, nên bước trước phải có chiều cao thấp hơn 1 đơn vị
            required_min = next_min - 1;
            required_max = next_max - 1;
        } else {
            // d[i] == -1 (chưa biết), bước trước chiều cao phải >= next_min-1 và <= next_max
            required_min = next_min - 1;
            required_max = next_max;
        }
        
        // Cập nhật khoảng khả thi bước i, phải thỏa mãn cả tiến và lùi
        final_min_height[i] = max(min_height_possible[i], required_min);
        final_max_height[i] = min(max_height_possible[i], required_max);

        if (final_min_height[i] > final_max_height[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> answer(n);
    int current_height = 0;

    // Xây dựng lại d với các giá trị cụ thể 0 hoặc 1
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            answer[i] = 0;
        } else if (d[i] == 1) {
            answer[i] = 1;
        } else {
            // d[i] == -1, chọn 0 nếu vẫn thỏa mãn khoảng chiều cao khả thi của bước tiếp theo
            int height_if_0 = current_height + 0;
            bool can_choose_0 = (final_min_height[i+1] <= height_if_0 && height_if_0 <= final_max_height[i+1]);
            answer[i] = can_choose_0 ? 0 : 1;
        }
        current_height += answer[i];
    }
            
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << ' ';
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
5
4
0 -1 -1 1
0 4
1 2
2 4
1 4
3
0 -1 -1
0 1
2 2
0 3
2
-1 -1
0 0
2 2
8
-1 -1 1 -1 -1 0 0 -1
0 0
0 1
0 2
0 2
1 3
0 4
2 5
4 5
1
0
1
*/
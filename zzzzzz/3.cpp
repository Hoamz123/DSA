#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break; // Kết thúc

        vector<int> arrival(n);
        for (int i = 0; i < n; ++i) {
            cin >> arrival[i];
        }

        stack<int> sideStreet; // Side street = stack
        int expected = 1; // Số xe cần ra tiếp theo
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            int car = arrival[i];

            // Nếu xe đúng số cần ra parade
            if (car == expected) {
                expected++;
            } else {
                // Đưa xe vào stack nếu chưa ra được
                while (!sideStreet.empty() && sideStreet.top() == expected) {
                    sideStreet.pop();
                    expected++;
                }

                // Nếu xe lớn hơn thì đẩy vào stack
                sideStreet.push(car);
            }
        }

        // Xử lý nốt stack
        while (!sideStreet.empty()) {
            if (sideStreet.top() == expected) {
                sideStreet.pop();
                expected++;
            } else {
                possible = false;
                break;
            }
        }

        cout << (possible ? "yes" : "no") << endl;
    }

    return 0;
}

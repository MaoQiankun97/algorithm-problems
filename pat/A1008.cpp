//
// Created by mqk on 2020/4/3.
//

#include "iostream"

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        int pre = 0;
        int cur;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> cur;
            sum += 5;

            if (cur > pre) {
                sum += (cur - pre) * 6;
            } else {
                sum += (pre - cur) * 4;
            }
            pre = cur;
        }
        cout << sum << endl;
    }

    return 0;
}

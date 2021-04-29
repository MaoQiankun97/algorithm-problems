#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> dp;

    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        dp = vector<int>(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            int max = INT32_MIN;
            for (int j = 2; j < i; ++j) {
                int now_max = dp[j] * dp[i-j];
                if (now_max > max) {
                    max = now_max;
                }
            }
            dp[i] = max;
        }

        return dp[n];
    }
};

int main() {
    Solution a;
    cout<<a.integerBreak(58);

    return 0;
}
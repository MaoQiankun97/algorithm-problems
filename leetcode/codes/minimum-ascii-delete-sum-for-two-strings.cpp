//
// Created by riddle on 2020/11/26.
//
#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    int minimumDeleteSum(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 0; i < text1.size(); ++i) {
            dp[i+1][0] = dp[i][0] + text1[i];
        }
        for (int i = 0; i < text2.size(); ++i) {
            dp[0][i+1] = dp[0][i] + text2[i];
        }

        for (int i = 0; i < text1.size(); ++i) {
            for (int j = 0; j < text2.size(); ++j) {
                if (text1[i] != text2[j]) {
                    dp[i+1][j+1] = min (dp[i][j+1] + text1[i], dp[i+1][j] + text2[j]);
                } else {
                    dp[i+1][j+1] = dp[i][j];
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};

int main() {
    Solution a;
    cout<<a.minimumDeleteSum("delete", "leet");

    return 0;
}
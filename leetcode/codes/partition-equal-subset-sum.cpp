//
// Created by riddle on 10/11/20.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"


using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        if (nums.size() < 2) {
            return false;
        }
        long long sum = 0;
        for (auto &num: nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum >>= 1;
        for (auto &num: nums) {
            if (num == sum) return true;
            if (num > sum) return false;
        }
        // dp[i][j] 表示 从数组0到i为止，能否选出一个总和等于j的子数组
        // 则有dp[i][j] = dp[i-1][j] || dp[i-1][j - num[i]] (j >= nums[i])
        //    dp[i][j] = dp[i-1][j] ( j < nums[i])
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));
        dp[0][nums[0]] = true;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[nums.size() - 1][sum];
    }
};

int main() {
    vector<int> input1 = {99, 1};
    Solution a;
    cout << a.canPartition(input1);

    return 0;
}

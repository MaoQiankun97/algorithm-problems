#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "set"

using namespace std;


class Solution {
public:
    static int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        vector<int> dp1(size-1, 0);
        vector<int> dp2(size-1, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for (int i = 2; i < size; ++i) {
            if (i < size - 1) {
                dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
            }
            if (i > 2) {
                dp2[i-1] = max(dp2[i - 3] + nums[i], dp2[i - 2]);
            }
        }

        return dp1[size-2] > dp2[size-2] ? dp1[size-2] : dp2[size-2];
    }
};
// dp[i] = max(dp[i-2] + nums[i], dp[i-1]);

int main() {
    vector<int> input = {1, 1, 1};
    cout << Solution::rob(input);
    cout << endl;
    return 0;
}

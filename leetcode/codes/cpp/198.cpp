#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    static int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        if (nums.size() == 3) {
            return max(nums[0] + nums[2], nums[1]);
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        for (int i = 3; i < nums.size(); ++i) {
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        }

        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};

int main()
{
    vector<int> input = {2,7,9,3,1};
    cout<<Solution::rob(input);
    cout<<endl;
    return 0;
}

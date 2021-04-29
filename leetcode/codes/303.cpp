#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = nums[i-1] + nums[i];
        }
        dp = nums;
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return dp[j];
        } else {
            return dp[j] - dp[i-1];
        }
    }

private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main()
{
    vector<int> input = {2,7,9,3,1};
    NumArray * a = new NumArray(input);
    cout<<a->sumRange(1, 4);
    cout<<endl;
    return 0;
}

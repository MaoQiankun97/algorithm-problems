#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    static int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> z(nums.size(), 0);
        vector<int> n(nums.size(), 0);
        z[0] = nums[0];
        n[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                z[i] = 0;
                n[i] = 0;
            } else {
                z[i] = max(max(nums[i], z[i - 1] * nums[i]), n[i-1] * nums[i]);
                n[i] = min(min(nums[i], n[i - 1] * nums[i]), z[i-1] * nums[i]);
            }
        }

        int result = 0;
        for (auto& item: z) {
            if (item > result) {
                result = item;
            }
        }

        return result;
    }
};

int main()
{
    vector<int> input = {2,-7,9,-3,1};
    cout<<Solution::maxProduct(input);
    cout<<endl;
    return 0;
}

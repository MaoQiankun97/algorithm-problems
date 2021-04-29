#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int _max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > 0) {
                nums[i] += nums[i - 1];
            }
            if (nums[i] > _max) _max = nums[i];
        }

        return _max;
    }
};

int main() {
    Solution a;
    vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << a.maxSubArray(input);

    return 0;
}

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    static int findMin(vector<int>& nums) {
        int _ = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                return nums[i];
            }
        }

        return _;
    }
};

int main()
{
    vector<int> input = {2, 2, 2, 0, 1};
    cout<<Solution::findMin(input);
    cout<<endl;
    return 0;
}

//
// Created by riddle on 10/11/20.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        vector<int> d(nums.size(), 0);
        d[0] = nums[0];
        int len = 0;
        for (auto &item: nums) {
            if (item > d[len]) {
                d[++len] = item;
                continue;
            }
            int pos = -1;
            int l = 0; int r = len;
            while (l <= r) {
                int mid = (l+r) >> 1;
                if (d[mid] >= item) {
                    r = mid - 1;
                    continue;
                }
                if (d[mid] < item) {
                    pos = mid;
                    l = mid + 1;
                    continue;
                }
            }
            d[pos+1] = item;
        }

        return len+1;
    }
};

int main () {
    vector<int> input = {10,9,2,5,3,7,101,18};
    Solution a;
    cout<<a.lengthOfLIS(input);

    return 0;
}
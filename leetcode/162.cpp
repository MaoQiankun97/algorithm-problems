//
// Created by riddle on 2020/10/9.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    static int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        checkHelper(nums, left, right, result);

        return result;
    }

    static void checkHelper(vector<int>& nums, int left, int right, int &result) {
        if (result != -1) {
            return;
        }
        if (left > right) {
            return;
        }
        int mid = (left + right) >> 1;
        if (checkResult(nums, mid)) {
            result = mid;
        }
        checkHelper(nums, left, mid - 1, result);
        checkHelper(nums, mid + 1, right, result);
    }

private:
    static bool checkResult(const vector<int>& nums, int i) {
        if (0 == i) {
            if (nums[i] > nums[i+1]) {
                return true;
            }
        } else if (nums.size() - 1 == i) {
            if (nums[i] > nums[i-1]) {
                return true;
            }
        } else {
            if (nums[i] > nums[i+1] && nums[i] > nums[i-1]) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> input = {2,7,9,3,1};
    cout<<Solution::findPeakElement(input);
    cout<<endl;
    return 0;
}

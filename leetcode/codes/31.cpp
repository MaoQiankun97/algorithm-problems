#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    void swap(int &a, int &b) {
        a = a^b;
        b = a^b;
        a = a^b;
    }

    void nextPermutation(vector<int>& nums) {
        int m = nums.size();
        if (m < 2) return;

        int right = m-1; int left = m-2;
        int i, t; int t1, t2; bool flag = false;
        t = nums[right];
        while (left >= 0) {
            if (left >= 0 && nums[left] < t)
                for (i = right; i < m; ++i)
                    if (nums[i] > nums[left]) {
                        swap(nums[left], nums[i]);
                        return;
                    }

            t = nums[left];
            t1 = left; t2 = right;
            while (nums[t1] > nums[t2] && t2 < m) {
                swap(nums[t1], nums[t2]);
                t1++;
                t2++;
            }

            left--;
            right--;
        }
    }
};

int main()
{
    Solution a;
    vector<int> nums = {1, 2, 3};
    a.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<" ";
        // except： 1 3 2
    }
    return 0;
}
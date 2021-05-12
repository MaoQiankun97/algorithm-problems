//
// Created by riddle on 2021/2/4.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        int sum = 0;
        int max_sum = 0;
        for (int i = 0; i <= right; ++i) {
            sum += nums[i];
        }
        max_sum = sum;
        while (++right < nums.size()) {
            sum -= nums[left++];
            sum += nums[right];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }

        return (double) max_sum / k;
    }
};

int main() {
    Solution a;
    vector<int> input = {1,12,-5,-6,50,3};
    cout<<a.findMaxAverage(input, 4);

    return 0;
}
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv,nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
public:
    static vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, vector<int>> d;
        for (int i  = 0; i < nums.size(); ++i) {
            if (d.count(nums[i])) {
                d[nums[i]].push_back(i);
            } else {
                vector<int> ___;
                ___.push_back(i);
                d[nums[i]]  = ___;
            }
        }
        sort(nums.begin(), nums.end());
        int max_index = -1;
        for (int i  = 1; i < nums.size(); ++i) {
            int _i = nums[0] + nums[i];
            if (_i <= target && i > max_index) {
                max_index = i;
            } else if (_i > target) {
                break;
            }
        }
        vector<int> result;
        for (int i = 0; i < max_index; ++i) {
            for (int j = max_index; j > i; --j) {
                int _t = nums[i] + nums[j];
                if (_t == target) {
                    result.push_back(d[nums[i]][0]);
                    result.push_back(d[nums[j]].size() > 1 ? d[nums[j]][1] : d[nums[j]][0]);
                    return result;
                } else if (_t > target) {
                    continue;
                } else {
                    break;
                }
            }
        }
        return vector<int>();
    }
};

int main()
{
    int64_t t = getCurrentTime();
    vector<int> nums = {0, 4, 3, 0};
    int target = 0;
    vector<int> result = Solution::twoSum(nums, target);
    for (const auto &_r: result) {
        cout<<_r<<" ";
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

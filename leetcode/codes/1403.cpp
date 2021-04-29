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
    static vector<int> minSubsequence(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        int t = 0;
        vector<int> result;
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; --i) {
            t += nums[i];
            result.push_back(nums[i]);
            if (t > sum / 2) {
                return result;
            }
        }

    }
};


int main()
{
    int64_t t = getCurrentTime();
    vector<int> input = {4,4,7,6,7};
    vector<int> result = Solution::minSubsequence(input);
    for (auto item: result) {
        cout<<item<<" ";
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

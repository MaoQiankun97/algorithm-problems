#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv;
    gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int i;
        for (i = 0; i < nums.size(); ++i) {
                if (nums[i] >= target) {
                    break;
            }
        }
        return i;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> nums = {0};
    cout<<a.searchInsert(nums, 1);
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}
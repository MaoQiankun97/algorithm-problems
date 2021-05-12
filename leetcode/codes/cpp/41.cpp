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
    void swap(vector<int>& nums, int i, int j) {
        nums[i] = nums[i]^nums[j];
        nums[j] = nums[i]^nums[j];
        nums[i] = nums[i]^nums[j];
    }

public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ) {
            if (nums[i]>nums.size() || nums[i]<=0 || nums[i] == i+1) ++i;
            else {
                if (nums[i] == nums[nums[i]-1]) nums[i] = 0;
                else
                    swap(nums, i, nums[i]-1);
            }
        }
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j]!=j+1) return j+1;
        }
        return nums.size()+1;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {1,1};
    cout<<a.firstMissingPositive(input);
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}

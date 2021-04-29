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
private:
    bool search1(vector<int>& nums, int begin, int target) {
        while (begin < nums.size()) {
            if (nums[begin] == target) return true;
            if (nums[begin] > target) return false;
            if (begin+1<nums.size() && nums[begin+1] < nums[begin])
                return false;
            begin++;
        }

        return false;
    }
    bool search2(vector<int>& nums, int end, int target) {
        while (end >= 0) {
            if (nums[end] == target) return true;
            if (nums[end] < target) return false;
            if (end-1>=0 && nums[end-1] > nums[end]) return false;
            end--;
        }

        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        if (target == nums[0]) return true;
        if (target>nums[0]) return search1(nums, 1, target);
        if (target<nums[0]) return search2(nums, nums.size()-1, target);
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {3, 4, 5, 6, 1, 2, 2};
    cout<<a.search(input, 11);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

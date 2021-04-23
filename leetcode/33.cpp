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
    int bsearch(vector<int>& nums, int target, int start, int end) {
        if (start>end)
            return -1;
        int mid = (start+end)>>1;
        if (target == nums[mid]) return mid;
        else if (target > nums[mid]) return bsearch(nums, target, mid+1, end);
        else return bsearch(nums, target, start, mid-1);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n<=0) return -1;
        if (target == nums[0]) return 0;
        int k = 0; int i;
        for (i = 0; i < n-1; ++i) {
            if (nums[i+1] < nums[i]) {
                break;
            }
        }
        k = i;
        if (target > nums[0]) {
            return bsearch(nums, target, 0, k);
        }
        else if (target < nums[0]){
            return bsearch(nums, target, k+1, n-1);
        }
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<a.search(nums, 0);
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}
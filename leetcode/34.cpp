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
    void bsearch(vector<int>& nums, int target, int start, int end, vector<int>& r) {
        if (start>end) return;
        int mid = (start+end)>>1;
        if (nums[mid] == target) {
            r.push_back(mid);
            bsearch(nums, target, mid+1, end, r);
            bsearch(nums,target, start, mid-1, r);
        }
        else if (nums[mid] > target) {
            return bsearch(nums, target, start, mid-1, r);
        } else {
            return bsearch(nums, target, mid+1, end, r);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp;
        bsearch(nums, target, 0, nums.size()-1, temp);
        sort(temp.begin(), temp.end());
        if (temp.size() <= 0) return {-1, -1};
        return {temp[0], temp[temp.size()-1]};
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> nums = {0,1,2,4,5,5,5,5,5,6,6,6,6,6,6,7,9,14};
    vector<int> r = a.searchRange(nums, 5);
    cout<<r[0]<<" "<<r[1];
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}
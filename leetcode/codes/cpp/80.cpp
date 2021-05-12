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
    void swap(vector<int>& nums, int i, int j) {
        if (i == j) return;
        nums[i] = nums[i]^nums[j];
        nums[j] = nums[i]^nums[j];
        nums[i] = nums[i]^nums[j];
    }
    void del(vector<int>& nums, int start, int end, int& len) {
        int i = start; int j = end;
        while (j<len) {
            swap(nums, i, j);
            i++;
            j++;
        }
        len-=(end-start);
    }
public:
    int removeDuplicates(vector<int>& nums) {
        int start, end, len;
        start = 0;
        end = 0;
        len = nums.size();

        for (int i = 0; i < len; ++i) {
            if (i+2 < len && nums[i+2] == nums[i]) {
                start = i+2;
                end = i+2;
                while (end < len && nums[end]==nums[end-1]) end++;
                del(nums, start, end, len);
            }
        }
        return len;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {0, 0, 0, 0};
    cout<<a.removeDuplicates(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

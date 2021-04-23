#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
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
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ) {
            if (i == nums.size()-1) return nums[i];
            if (nums[i]!=nums[i+1]) return nums[i];
            while (nums[i+1] == nums[i]) i++;
            i++;
        }
    }
};
int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {2, 2, 1};
    cout<<a.singleNumber(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
//class Solution {
//private:
//    void getResult(vector<int>& nums, int i, int& max) {
//        if (i>=nums.size())
//            return;
//        int t = 0; int j;
//        for (j = i; j < nums.size(); ++j) {
//            t+=nums[j];
//            if (t>=max) max = t;
//        }
//        getResult(nums, i+1, max);
//    }
//
//public:
//    int maxSubArray(vector<int>& nums) {
//        if (nums.size()<=0) return 0;
//        int i = 0;
//        int max = nums[0];
//        getResult(nums, i, max);
//        return max;
//    }
//};

class Solution {
public:
    int maxSubArray(vector<int> A) {
        int n = A.size();
        if (n<=0) return 0;
        int ans=A[0],i,j,sum=0;
        for(i=0;i<n;i++){
            sum+=A[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<a.maxSubArray(input);
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}

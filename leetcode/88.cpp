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
        if (i==j) return;
        nums[i] = nums[i]^nums[j];
        nums[j] = nums[i]^nums[j];
        nums[i] = nums[i]^nums[j];
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m+n; ++i) {
            nums1[i] = nums2[i-m];
        }
        if (m == 0 || n == 0)
            return;
        int start = 0; int end = m+n-1;
        for (int i = m; i < m+n; ++i) {
            while (nums1[i]<nums1[i-1]) {
                int j;
                for (j = i-1; j >= 0 ; --j) {
                    if (nums1[j]>nums1[i]) continue;
                    break;
                }
                swap(nums1, i, j+1);
            }
        }
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input1 = {1, 2, 3, 0, 0, 0};
    vector<int> input2 = {2, 5, 6};
    a.merge(input1, 3, input2, 3);
    for (int i = 0; i < input1.size(); ++i) {
        cout<<input1[i]<<" ";
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
        if (i==j)
            return;
        nums[i] = nums[i]^nums[j];
        nums[j] = nums[i]^nums[j];
        nums[i] = nums[i]^nums[j];
    }
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int k = i;
        while (k <= j) {
            if (nums[k] == 2) {
                swap(nums, k, j);
                j--;
            }
            if (nums[k] == 0 && k==i) {
                i++;
                k++;
            }
            if (nums[k] == 0 && k!=i) {
                swap(nums, k, i);
                i++;
            }
            if (nums[k] == 1) {
                k++;
            }
        }
    }
};


int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {2};
    a.sortColors(input);
    for (int i = 0; i < input.size(); ++i) {
        cout<<input[i]<<" ";
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
    bool canJump(vector<int> A) {
        int n = A.size();
        int i = 0;
        for (int reach = 0; i < n && i <= reach; ++i) {
            reach = max(i + A[i], reach);
            if (reach >= n-1) return true;
        }
        return false;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {2,3,1,1,4};
    cout<<a.canJump(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

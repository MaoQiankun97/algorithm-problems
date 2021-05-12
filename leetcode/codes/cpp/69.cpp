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
    int mySqrt(int x) {
        if (x==0) return 0;
        int left = 1, right = x;
        int mid;
        while (left<=right) {
            mid = left + (right-left)/2;
            if (mid > x/mid) {
                right = mid-1;
            } else {
                if (mid+1 > x/(mid+1)) {
                    return mid;
                }
                left = mid+1;
            }
        }
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.mySqrt(1);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (x == 1) return 1.0;
        if (n==0) return 1.0;
        if (n==1) return x;
        if (n < 0){
            if (n%2==0)
                return myPow(1/(x*x), -(n/2));
            else
                return (1/x)*myPow(1/x, -(n+1));
        }

        if (n%2==0)
            return myPow(x*x, n/2);
        else
            return x*myPow(x, n-1);
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.myPow(2.00000, -2147483648);
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}

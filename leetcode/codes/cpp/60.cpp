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
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
        // 1 1 2 6
        k--;
        for (int i = n - 1; i >= 0; --i) {
            int j = k/f[i];
            k %= f[i];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.getPermutation(4, 7);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

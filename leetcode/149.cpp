#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv,nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

struct Node {
    int a_1; // 系数分子
    int a_2; // 系数分母
    int b;
    int num; // 数量
};

class Solution {
public:
    static int maxPoints(vector<vector<int>>& points) {
        // 一条直线一定可以表示为 y = a * x + b的形式
        // 用Node来表示一条直线.
    }
};

int main()
{
    int64_t t = getCurrentTime();
    vector<vector<int>> param = {
            {1, 2},
            {3, 2},
            {5, 3},
            {4, 1},
            {2, 3},
            {1, 4}
    };
    cout<<Solution::maxPoints(param);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

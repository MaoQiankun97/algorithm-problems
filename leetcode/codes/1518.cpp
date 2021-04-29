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

class Solution {
public:
    // 设 酒+瓶 价值 x 酒瓶价值 1
    // 有 x = numExchange (numExchange个酒瓶能换一瓶酒)
    // 有 酒 价值 numExchange - 1
    // 目前现有总价 numBottles * (酒+瓶)的价值 = numBottles * numExchange
    // 故最多可以喝到 numBottles * numExchange / numExchange - 1 瓶酒 （考虑借瓶子的情况)
    // 题设不允许借瓶子 故最终手上 至少有一个瓶子 价值为 1
    // 故最多可以喝到 (numBottles * numExchange - 1) / (numExchange - 1) 瓶酒
    static int numWaterBottles(int numBottles, int numExchange) {
        return (numBottles * numExchange - 1) / (numExchange - 1);
    }
};


int main()
{
    int64_t t = getCurrentTime();
    cout<<Solution::numWaterBottles(15, 4);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

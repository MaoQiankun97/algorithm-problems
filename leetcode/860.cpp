#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "set"
#include <sys/time.h>      //添加头文件

using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv, nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
public:
    static bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (auto &item : bills) {
            if (item == 5) {
                five++;
            }
            if (item == 10) {
                five--;
                ten++;
            }
            if (item == 20) {
                if (ten > 0) {
                    ten--;
                    five--;
                } else {
                    five-=3;
                }
            }
            if (five < 0 || ten < 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int64_t t = getCurrentTime();
    vector<int> input = {20, 5, 5, 5};
    cout << Solution::lemonadeChange(input);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

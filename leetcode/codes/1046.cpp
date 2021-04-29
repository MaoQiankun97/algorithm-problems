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
    gettimeofday(&tv, nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
public:
    static int lastStoneWeight(vector<int> &stones) {
        sort(stones.begin(), stones.end());
        while (stones.size() > 1) {
            int m1 = stones[stones.size() - 1];
            int m2 = stones[stones.size() - 2];
            stones.pop_back();
            stones.pop_back();
            if (m1 != m2) {
                stones.push_back(m1 - m2);
            }
            sort(stones.begin(), stones.end());
        }

        return stones.size() == 1 ? stones[0] : 0;
    }
};

int main() {
    int64_t t = getCurrentTime();
    vector<int> input = {2,7,4,1,8,1};
    cout << Solution::lastStoneWeight(input);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

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
    static int minCostToMoveChips(vector<int>& position) {
        int position1Num = 0;
        int position2Nu = 0;
        for (int i = 0; i < position.size(); ++i) {
            if (position[i]%2 == 1) {
                position1Num++;
            } else {
                position2Nu++;
            }
        }

        return min(position1Num, position2Nu);
    }
};

int main() {
    int64_t t = getCurrentTime();
    vector<int> input = {2, 2, 2, 3, 3};
    cout << Solution::minCostToMoveChips(input);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

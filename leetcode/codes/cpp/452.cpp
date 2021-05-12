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

bool compare(vector<int> & a, vector<int> & b) {
    return a[1] < b[1];
}

class Solution {
public:
    static int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        if (points.size() == 1) {
            return 1;
        }
        sort(points.begin(), points.end(), compare);
        int _cur_end = points[0][1];
        int result = 1;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] > _cur_end) {
                _cur_end = points[i][1];
                result++;
            }
        }

        return result;
    }
};

int main() {
    int64_t t = getCurrentTime();
    vector<vector<int>> input = {
            {1, 2},
            {2, 3},
            {3, 4},
            {4, 5}
    };
    cout << Solution::findMinArrowShots(input);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

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
    static int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> oset;
        for (auto & item : obstacles) {
            oset.insert(make_pair(item[0], item[1]));
        }
        int i = 0;
        int j = 0;
        int f = 0; // 0 1 2 3 上 右 下 左
        int result = 0;
        for (auto & item : commands) {
            if (item == -1) {
                f = (f+1)%4;
            } else if (item == -2) {
                f = (f+3)%4;
            } else {
                if (f == 0) {
                    for (int k = 0; k < item; ++k) {
                        if (oset.find(make_pair(i, j + 1)) != oset.end()) {
                            break;
                        }
                        j++;
                        result = max(result, i*i+j*j);
                    }
                } else if (f == 1) {
                    for (int k = 0; k < item; ++k) {
                        if (oset.find(make_pair(i + 1, j)) != oset.end()) {
                            break;
                        }
                        i++;
                        result = max(result, i*i+j*j);
                    }
                } else if (f == 2) {
                    for (int k = 0; k < item; ++k) {
                        if (oset.find(make_pair(i, j - 1)) != oset.end()) {
                            break;
                        }
                        j--;
                        result = max(result, i*i+j*j);
                    }
                } else {
                    for (int k = 0; k < item; ++k) {
                        if (oset.find(make_pair(i - 1, j)) != oset.end()) {
                            break;
                        }
                        i--;
                        result = max(result, i*i+j*j);
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    int64_t t = getCurrentTime();
    vector<int> input = {7, -2, -2, 7, 5};
    vector<vector<int>> input1 = {
            {-3,2},{-2,1},{0,1},{-2,4},{-1,0},{-2,-3},{0,-3},{4,4},{-3,3},{2,2}
    };
    cout << Solution::robotSim(input, input1);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

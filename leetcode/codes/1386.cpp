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
    static int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
        // fdsfdsdsasfdsawwf
        unordered_map<int, int> resultHelp;

        for (int i = 0; i < reservedSeats.size(); ++i) {
            int _row = reservedSeats[i][0] - 1;
            int _column = reservedSeats[i][1];
            if (_column != 1 && _column != 10) {
                if (resultHelp.find(_row) == resultHelp.end()) {
                    resultHelp[_row] = 0b1111;
                }
            } else {
                continue;
            }
            if (_column == 2 || _column == 3) {
                resultHelp[_row] &= 7;
            } else if (_column == 4 || _column == 5) {
                resultHelp[_row] &= 11;
            } else if (_column == 6 || _column == 7) {
                resultHelp[_row] &= 13;
            } else if (_column == 8 || _column == 9) {
                resultHelp[_row] &= 14;
            }
        }

        int sum = n << 1;
// 110121
        auto it = resultHelp.begin();
        while (it != resultHelp.end()) {
            int re = it->second;
            if ((re&0b1100) == 0b1100) {
                sum -= 1;
            } else if ((re&0b0011) == 0b0011) {
                sum-=1;
            } else if ((re&0b0110) == 0b0110){
                sum -=1;
            } else {
                sum-=2;
            }
            it++;
        }

        return sum;
    }
};


int main() {
    int64_t t = getCurrentTime();
    vector<vector<int>> input = {
            {4, 3},
            {1, 4},
            {4, 6},
            {1, 7}
    };
    cout << Solution::maxNumberOfFamilies(4, input);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

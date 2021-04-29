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
    static int minDeletionSize(vector<string>& A) {
        if (A.size() == 0) {
            return 0;
        }
        int strLength = A[0].size();

        int result = 0;
        for (int i = 0; i < strLength; ++i) {
            char _pre = A[0][i];
            for (int j = 1; j < A.size(); ++j) {
                if (A[j][i] >= _pre){
                    _pre = A[j][i];
                    continue;
                } else {
                    result++;
                    break;
                }
            }
        }

        return result;
    }
};

int main() {
    int64_t t = getCurrentTime();
    vector<string> input = {
            "cba", "daf", "ghi"
    };
    cout << Solution::minDeletionSize(input);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

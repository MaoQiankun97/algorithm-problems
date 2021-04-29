#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>      //添加头文件

using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv;
    gettimeofday(&tv, NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
public:
    int videoStitching(vector<vector<int>> &clips, int T) {
        int max_start = 0;
        int r = 0;
        while (max_start < T) {
            // 遍历找到start小于等于max_start， end最大的值
            int max_end = max_start;
            for (int i = 0; i < clips.size(); ++i) {
                if (clips[i][0] <= max_start) {
                    if (clips[i][1] > max_end) {
                        max_end = clips[i][1];
                    }
                }
            }
            if (max_end == max_start) {
                return -1;
            }
            max_start = max_end;
            r++;
        }
        return r;
    }
};


int main() {
    Solution a;
    int64_t t = getCurrentTime();
    cout << a.videoStitching(1);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

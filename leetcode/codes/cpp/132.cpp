#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv;
    gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
public:
    int minCut(string s) {
        if (s.length()<=1) return 0;

        vector<int> minCut;
        for (int i = 0; i <= s.length(); ++i) {
            minCut.push_back(i-1);
        }
        vector<vector<bool>> isPali(s.length(), vector<bool>(s.length(), false));

        for (int i = 1; i < s.length(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (s[j]==s[i]&&(i-j<2||isPali[i-1][j+1])) {
                    isPali[i][j] = true;
                    minCut[i+1] = min(minCut[i+1], minCut[j]+1);
                }
            }
        }
        return minCut[s.length()];
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.minCut("abab");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

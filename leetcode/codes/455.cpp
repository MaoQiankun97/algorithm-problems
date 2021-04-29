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
    static int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0; int j = 0;
        int result = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i]<=s[j]) {
                i++;
                j++;
                result++;
            } else {
                j++;
            }
        }

        return result;
    }
};
int main() {
    int64_t t = getCurrentTime();
    vector<int> input = {10, 9, 8, 7};
    vector<int> input1 = {5, 6, 7, 8};
    cout << Solution::findContentChildren(input, input1);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

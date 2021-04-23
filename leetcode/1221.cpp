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
    gettimeofday(&tv,nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
public:
    static int balancedStringSplit(string s) {
        int result = 0;
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == 'L') {
                i -= 1;
            } else if (s[j] == 'R') {
                i += 1;
            }
            if (i == 0) {
                result += 1;
            }
        }

        return result;

    }
};


int main()
{
    int64_t t = getCurrentTime();
    cout<<Solution::balancedStringSplit("RRRRLLLLRLRL");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

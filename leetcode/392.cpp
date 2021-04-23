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
    static bool isSubsequence(string s, string t) {
        if (s.size() == 0) {
            return true;
        }
        if (t.size() < s.size()) {
            return false;
        }
        int i = 0;
        for (int j = 0; j < t.size(); ++j) {
            if (s[i] == t[j]) {
                i++;
                if (i == s.size()) {
                    return true;
                }
            }
        }

        return false;
    }
};


int main()
{
    int64_t t = getCurrentTime();
    cout<<Solution::isSubsequence("abc", "aabbdasdghudwighofgs");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
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
    int minDistance(string word1, string word2) {
        if (word1.length() == 0 || word2.length() == 0) {
            return max(word1.length(), word2.length());
        }
        int l1 = word1.length();
        int l2 = word2.length();
        int dp[l1+1][l2+1];
        dp[0][0] = 0;
        int i, j;
        for (i = 1; i <= l1; ++i) {
            dp[i][0] = i;
        }
        for (i = 1; i <= l2; ++i) {
            dp[0][i] = i;
        }
        for (i = 1; i <= l1; ++i) {
            for (j = 1; j <= l2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])); // 当word1[i-1]!=word2[j-1]时,
                    // 将word1 0~i-1转变为word2 0~j-1需要新增或删除或修改一个字符
                }
            }
        }

        return dp[l1][l2];
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.minDistance("maoqiankun", "hello");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

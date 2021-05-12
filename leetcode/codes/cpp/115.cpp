#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv;
    gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    /**
     * 再次证明了字符串匹配之类的优先考虑dp
     * 先设定边界值，再寻找一般性规律求解
     */
    int numDistinct(string s, string t) {
        if (t.length() == 0) return 1;
        if (s.length() < t.length()) return 0;
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < t.length(); ++i) {
            dp[0][i] = 0;
        }
        for (int i = 1; i < s.length(); ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 1; j <= t.length(); ++j) {
                if (j>i) dp[i][j] = 0;
                else {
                    if (s[i-1]==t[j-1])
                        dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[s.length()][t.length()];
    }
};


int main()
{
    Solution a;
    int64_t t = getCurrentTime();
//    cout<<a.numDistinct("babgbag", "bag");
    cout<<a.numDistinct("rabbbit", "rabbit");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

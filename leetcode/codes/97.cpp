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

// 回溯法 不能Ac
//class Solution {
//private:
//    bool isInterleave(string s1, string s2, string s3, int i, int j, int k, int l1, int l2, int l3) {
//        if (k==l3 && i==l1 && j==l2)
//            return true;
//        if (i<l1 && s1[i]==s3[k]) {
//            i++;
//            k++;
//            if (!isInterleave(s1, s2, s3, i, j, k, l1, l2, l3)) {
//                i--;
//                k--;
//            } else {
//                return true;
//            }
//        }
//        if (j<l2 && s2[j]==s3[k]) {
//            j++;
//            k++;
//            if (!isInterleave(s1, s2, s3, i, j, k, l1, l2, l3)) {
//                j--;
//                k--;
//            } else {
//                return true;
//            }
//        }
//        return false;
//    }
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        int l1 = s1.length();
//        int l2 = s2.length();
//        int l3 = s3.length();
//        if (l3!=l1+l2) return false;
//        return isInterleave(s1, s2, s3, 0, 0, 0, l1, l2, l3);
//    }
//};

// dp 类似的字符串匹配还是用dp比较好, 递归的时间复杂度一般较高
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        if (l3!=l1+l2) return false;

        vector<vector<bool>> dp(l1+1, vector<bool>(l2+1, false));
        // 初始化dp边界
        dp[0][0] = true;
        for (int i = 1; i <= l1; ++i) {
            dp[i][0] = dp[i-1][0] && (s1[i-1]==s3[i-1]);
        }
        for (int i = 1; i <= l2; ++i) {
            dp[0][i] = dp[0][i-1] && (s2[i-1]==s3[i-1]);
        }
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                dp[i][j] = (dp[i-1][j] && s3[i+j-1] == s1[i-1])
                        || (dp[i][j-1] && s3[i+j-1] == s2[j-1]);
            }
        }

        return dp[l1][l2];
    }
};


int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
            "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
            "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
//    cout<<a.isInterleave("ab", "cd", "acdb");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string _s: wordDict)
            dict.insert(_s);
        return help(s, dict);
    }
private:
    bool help(string s, unordered_set<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (dp[j]) {
                    string word = s.substr(j, i-j);
                    if (wordDict.find(word)!=wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout<<a.wordBreak(s, wordDict);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

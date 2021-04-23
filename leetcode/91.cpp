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

//class Solution {
//private:
//    bool getResult(string s, int start, int end, int &r) {
//        if (start>end) return true;
//        if (s[start]<='9'&&s[start]>='1') {
//            r++;
//            if (!getResult(s, start+1, end, r))
//                r--;
//        }
//        if (start+1<=end && (s[start]=='1' && s[start+1]<='9' && s[start+1]>='0')||(s[start]=='2'&&s[start+1]<='6'&&s[start+1]>='0')) {
//            r++;
//            if (!getResult(s, start+2, end, r))
//                r--;
//        }
//        return false;
//    }
//public:
//    int numDecodings(string s) {
//        int r = 0;
//        getResult(s, 0, s.length()-1, r);
//        return r;
//    }
//};

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0')
            return 0;
        vector<int> dp(s.length(), 0);
        dp[0] = 1;
        for (int i = 1; i < s.length(); ++i) {
            int t = dp[i-1];
            if (s[i-1]=='1' && s[i] <= '9' && s[i] >= '0') {
                if (i-2>=0&&dp[i-2]!=0)
                    dp[i]+=dp[i-2];
                else dp[i] = 1;
            }
            if (s[i-1]=='2' && s[i]<='6' && s[i] >= '0') {
                if (i-2>=0&&dp[i-2]!=0)
                    dp[i]+=dp[i-2];
                else
                    dp[i] = 1;
            }
            if (s[i]>'0'&&s[i]<='9') {
                dp[i]+=dp[i-1];
            }
            if (dp[i]==0) return 0;
        }
        return dp[s.length()-1];
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.numDecodings("50926");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

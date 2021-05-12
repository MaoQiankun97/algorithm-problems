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
//
//class Solution {
//private:
//    void getResult(int start_m, int start_n, int m, int n, int &r) {
//        if (start_m>m||start_n>n) return;
//        if (start_m==m&&start_n==n) {
//            r++;
//            return;
//        }
//       if (start_n < n) getResult(start_m, start_n+1, m, n, r);
//       if (start_m < m) getResult(start_m+1, start_n, m, n, r);
//    }
//public:
//    int uniquePaths(int m, int n) {
//        int r = 0;
//        getResult(0, 0, m-1, n-1, r);
//        return r;
//    }
//};
//
//class Solution {
//private:
//    void getResult(int m, int n, int& r) {
//        if (m-1==0 || n-1==0) {
//            r++;
//            return;
//        }
//        if (m-1>0) getResult(m-1, n, r);
//        if (n-1>0) getResult(m, n-1, r);
//    }
//public:
//    int uniquePaths(int m, int n) {
//        int r = 0;
//        getResult(m, n, r);
//        return r;
//    }
//};

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < max(m, n); ++i) {
            if (i<n) dp[0][i] = 1;
            if (i<m) dp[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.uniquePaths(51, 9);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

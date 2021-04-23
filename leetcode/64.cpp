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
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp = grid;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    dp[i][j] = dp[i][j-1] + dp[i][j];
                    continue;
                }
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + dp[i][j];
            }
        }
        return dp[dp.size()-1][dp[dp.size()-1].size()-1];
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
     vector<vector<int>> input = {
             {1, 3, 1},
             {1, 5, 1},
             {4, 2, 1}
     };
//    vector<vector<int>> input = {
//            {1}
//    };
    cout<<a.minPathSum(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp = obstacleGrid;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                if (dp[i][j] == 1) {
                    dp[i][j] = -1;
                    continue;
                }
                if (i == 0){
                    if ((j-1>=0 && dp[i][j-1]!=-1) || j-1<0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = -1;
                }
                if (j==0) {
                    if ((i-1>=0 && dp[i-1][j]!=-1) || i-1<0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = -1;
                }
            }
        }
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[i].size(); ++j) {
                if (dp[i][j] == -1) continue;
                if (dp[i-1][j] == -1 && dp[i][j-1] == -1) {
                    dp[i][j] = -1;
                    continue;
                }
                if (dp[i-1][j] != -1 && dp[i][j-1] != -1) {
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                    continue;
                }
                if (dp[i-1][j]!=-1) dp[i][j] = dp[i-1][j];
                if (dp[i][j-1]!=-1) dp[i][j] = dp[i][j-1];
            }
        }

        return dp[dp.size()-1][dp[dp.size()-1].size()-1]==-1?0:dp[dp.size()-1][dp[dp.size()-1].size()-1];

    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    // vector<vector<int>> input = {
    //         {0, 0, 0},
    //         {0, 1, 0},
    //         {0, 0, 0}
    // };
    vector<vector<int>> input = {
            {1}
    };
    cout<<a.uniquePathsWithObstacles(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

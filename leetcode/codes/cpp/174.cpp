//
// Created by riddle on 2020/10/7.
//
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0) {
            return 1;
        }
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT32_MAX));
        dp[m-1][n] = 1;
        dp[m][n-1] = 1;
        for (int i = m-1; i >=0 ; --i) {
            for (int j = n-1; j >= 0; --j ) {
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) -dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};

int main() {
    vector<vector<int>> dungeon = {
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5}
    };
    Solution a;
    cout<<a.calculateMinimumHP(dungeon);

    return 0;
}
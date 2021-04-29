#include "iostream"
#include "vector"

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = 1;
        if (row > 0)
            column = matrix[0].size();
        for (int i = 0; i <= row; ++i) {
            vector<int> _;
            for (int j = 0; j <= column; ++j) {
                _.push_back(0);
            }
            dp.push_back(_);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp [row2+1][col1] + dp[row1][col1];
    }

private:
    vector<vector<int>> dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> input = {
            {-4, -5}
    };
    auto *numMatrix = new NumMatrix(input);
    cout<<numMatrix->sumRegion(0, 0, 0, 0);
    cout<<numMatrix->sumRegion(0, 0, 0, 1);
    cout<<numMatrix->sumRegion(0, 1, 0, 0);

    return 0;
}
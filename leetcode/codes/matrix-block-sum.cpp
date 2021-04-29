#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        if (mat.empty() || mat[0].empty()) {
            return mat;
        }
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (j == 0) {
                    mat[i][j] = mat[i-1][j] + mat[i][j];
                    continue;
                }
                if (i == 0) {
                    mat[i][j] = mat[i][j-1] + mat[i][j];
                    continue;
                }
                mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + mat[i][j];
            }
        }
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int start_i = max(0, i - K);
                int end_i = min(m-1, i + K);
                int start_j = max(0, j - K);
                int end_j = min(n-1, j + K);
                result[i][j] = mat[end_i][end_j];
                if (start_i > 0 && start_j > 0) {
                    result[i][j] += mat[start_i-1][start_j-1];
                }
                if (start_i > 0) {
                    result[i][j] -= mat[start_i-1][end_j];
                }
                if (start_j > 0) {
                    result[i][j] -= mat[end_i][start_j-1];
                }
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> input = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8 ,9}
    };

    Solution a;
    a.matrixBlockSum(input, 1);

    return 0;
}
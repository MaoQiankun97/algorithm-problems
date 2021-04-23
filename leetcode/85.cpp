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
    int maximalRectangle(vector<vector<char> > &matrix) {
        // 解释见 http://www.cnblogs.com/grandyang/p/4322667.html
        if (matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left[n], right[n], height[n];
        fill_n(left, n, 0);
        fill_n(right, n, n);
        fill_n(height, n, 0);
        int maxA = 0;
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
                if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else {
                    right[j] = n;
                    cur_right = j;
                }
                maxA = max(maxA, (right[j] - left[j]) * height[j]);
            }
        }
        return maxA;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<char>> input = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    cout<<a.maximalRectangle(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

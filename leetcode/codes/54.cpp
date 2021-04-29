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
private:
    void getResult(vector<vector<int>>& matrix, vector<int>& result, int begin, int m, int n) {
        if ((begin+1)*2>m+1 || (begin+1)*2>n+1) return;

        if (m%2!=0 && begin == m/2) {
            for (int i = begin; i < n-begin; ++i) {
                result.push_back(matrix[begin][i]);
            }
            return;
        }

        if (n%2!=0 && begin == n/2) {
            for (int i = begin; i < m-begin; ++i) {
                result.push_back(matrix[i][begin]);
            }
            return;
        }

        int queue_top[n+1]; int front_top = 0, rear_top = 0;
        int stack_bottom[n]; int top_bottom = -1;
        int queue_right[m+1]; int front_right = 0, rear_right = 0;
        int stack_left[m]; int top_left = -1;

        for (int i = begin; i < n-begin; ++i) {
            ++rear_top; ++top_bottom;
            queue_top[rear_top] = matrix[begin][i];
            stack_bottom[top_bottom] = matrix[m-begin-1][i];
        }

        for (int j = begin+1; j < m-begin-1; ++j) {
            ++rear_right; ++top_left;
            queue_right[rear_right] = matrix[j][n-begin-1];
            stack_left[top_left] = matrix[j][begin];
        }

        while (rear_top!=front_top) {
            ++front_top;
            result.push_back(queue_top[front_top]);
        }
        while (rear_right!=front_right) {
            ++front_right;
            result.push_back(queue_right[front_right]);
        }
        while (top_bottom!=-1) {
            result.push_back(stack_bottom[top_bottom]);
            top_bottom--;
        }
        while (top_left!=-1) {
            result.push_back(stack_left[top_left]);
            top_left--;
        }
        getResult(matrix, result, begin+1, m, n);
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size()<=0) return {};
        vector<int> result;
        getResult(matrix, result, 0, matrix.size(), matrix[0].size());
        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<int>> input = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12}
    };
    vector<int> r = a.spiralOrder(input);
    for (int i = 0; i < r.size(); ++i) {
        cout<<r[i]<<" ";
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

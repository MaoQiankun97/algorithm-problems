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
    void getResult(vector<vector<int>>& result, int begin, int i, int n) {
        // 从result数组的第i行第i列开始从begin开始设值
        // 如果result[i][i]已经大于最中间的一圈左上或最中间的一个数则结束
        if ((i+1)*2>n+1) return;
        if (n%2 != 0 && i == n/2) {
            result[i][i] = begin;
            return;
        }
        int t;
        for (int j = i; j < n-i; ++j) {
            t = j-i;
            result[i][j] = begin+t;
            result[n-i-1][j] = begin+(n-i-i-1)*4-(n-i-i-1)-t;
        }

        for (int k = i+1; k < n-i-1; ++k) {
            t = k-i-1;
            result[k][i] = begin+(n-i-i-1)*4-1-t;
            result[k][n-i-1] = begin+(n-i-i)+t;
        }

        getResult(result, begin+(n-i-i-1)*4, i+1, n);

    }

public:
    vector<vector<int>> generateMatrix(int n) {
        /*
         * input : 4
         * except: 1  2  3  4
         *        12 13 14  5
         *        11 16 15  6
         *        10  9  8  7
         *
         */
        if (n<0) return {};
        vector<vector<int>> result;
        result.resize(n, vector<int>(n));
        getResult(result, 1, 0, n);

        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<int>> r = a.generateMatrix(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

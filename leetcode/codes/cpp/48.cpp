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
    void swap(int &i, int &j) {
        if (i == j)
            return;
        i = i^j;
        j = i^j;
        i = i^j;
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i+1; j < matrix.size(); ++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int k = 0; k < matrix.size(); ++k) {
            for (int i = 0; i < matrix.size()/2; ++i) {
                swap(matrix[k][i], matrix[k][matrix.size()-i-1]);
            }
        }
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<int>> input = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    a.rotate(input);
    vector<vector<int>> r = input;
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<r.size()<<endl;
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}

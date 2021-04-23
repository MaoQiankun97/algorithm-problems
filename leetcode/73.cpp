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
    void setZeroes(vector<vector<int>>& matrix) {
        // 记录所有应该设为0的行号和列号
        vector<int> zero_i;
        vector<int> zero_j;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zero_i.push_back(i);
                    zero_j.push_back(j);
                }
            }
        }
        sort(zero_i.begin(), zero_i.end());
        sort(zero_j.begin(), zero_j.end());

        int a = 0; int b = 0;
        for (int k = 0; k < max(matrix.size(), matrix[0].size()); ++k) {
            if (a < zero_i.size() && k == zero_i[a]) {
                for (int i = 0; i < matrix[k].size(); ++i) {
                    matrix[k][i] = 0;
                }
                a++;
                while (a-1 < zero_i.size() && zero_i[a-1] == zero_i[a]) a++;
            }
            if (b < zero_j.size() && k == zero_j[b]) {
                for (int i = 0; i < matrix.size(); ++i) {
                    matrix[i][k] = 0;
                }
                b++;
                while (b < zero_j.size() && zero_j[b-1] == zero_j[b]) b++;
            }
        }
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<int>> input = {
            {0, 1, 2, 0},
            {1, 4, 1, 6},
            {1, 7, 8, 9}
    };
    a.setZeroes(input);
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[i].size(); ++j) {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

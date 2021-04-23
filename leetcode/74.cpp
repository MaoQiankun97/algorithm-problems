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
    bool search(vector<int> a, int target) {
        int mid;
        int left = 1, right = a.size()-1;
        while (left <= right) {
            mid = (left+right)/2;
            if (a[mid] == target) return true;
            if (a[mid] > target) right = mid-1;
            if (a[mid] < target) left = mid+1;
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int i;
        for (i = 0; i < matrix.size(); ++i) {
            if (target == matrix[i][0]) return true;
            if (target < matrix[i][0]) break;
        }
        if (i == 0) return false;
        return search(matrix[i-1], target);
    }
};


int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<int>> input = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };
    cout<<a.searchMatrix(input, 13);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

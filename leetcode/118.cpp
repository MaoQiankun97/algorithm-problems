#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
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
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> result;
        result.push_back({1});
        int i = 2; int j;
        vector<int> temp;
        while (i <= numRows) {
            temp = result[result.size()-1];
            int n = (i-1)>>1;
            vector<int> t;
            for (j = 0; j <= n; ++j) {
                t.push_back(temp[j]+(j-1>=0?temp[j-1]:0));
            }
            for (j = n+1; j < i; ++j) {
                t.push_back(t[i-1-j]);
            }
            result.push_back(t);
            i++;
        }

        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<int>> r = a.generate(5);

    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

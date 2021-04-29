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
    vector<int> getRow(int rowIndex) {
        int i = 1; int j;
        vector<int> temp = {1};
        while (i <= rowIndex) {
            int n = i>>1;
            vector<int> r;
            for (j = 0; j <= n; ++j) {
                r.push_back(temp[j]+(j-1>=0?temp[j-1]:0));
            }
            for (j = n+1; j <= i; ++j) {
                r.push_back(r[i-j]);
            }
            i++;
            temp = r;
        }

        return temp;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> r = a.getRow(5);

    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

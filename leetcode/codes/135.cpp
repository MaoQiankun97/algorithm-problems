#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
    int candy(vector<int>& ratings) {
        if (ratings.size()==0) return 0;
        vector<int> res(ratings.size(), 1);
        int i = 1, j = ratings.size()-2;
        for ( ; i < ratings.size(); ++i) {
            if (ratings[i]>ratings[i-1]) {
                res[i] = res[i-1]+1;
            }
        }
        for ( ; j >= 0; --j) {
            if (ratings[j]>ratings[j+1]) {
                res[j] = max(res[j], res[j+1]+1);
            }
        }
        int sum = 0;
        for (int v: res) {
            sum+=v;
        }
        return sum;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {1, 0, 2};
    cout<<a.candy(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

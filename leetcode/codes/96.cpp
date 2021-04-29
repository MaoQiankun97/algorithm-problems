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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int numTrees(int n) {
        // 求卡特兰数 采用数学归纳法计算
        long c = 1;
        for (int i = 1; i <= n; ++i) {
            c = c*(2*(2*i-1))/(i+1);
        }
        return static_cast<int>(c);
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.numTrees(17);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

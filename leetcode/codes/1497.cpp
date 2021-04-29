#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv,nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

//给你一个整数数组 arr 和一个整数 k ，其中数组长度是偶数，值为 n 。
//
//现在需要把数组恰好分成 n / 2 对，以使每对数字的和都能够被 k 整除。
//
//如果存在这样的分法，请返回 True ；否则，返回 False 。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/check-if-array-pairs-are-divisible-by-k
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    static bool canArrange(vector<int>& arr, int k) {
        if (k == 1) {
            return true;
        }
        int needCheckNum = 0;
        vector<int> help(k);
        for (int i = 1; i < k; ++i) {
            help[i] = 0;
        }
        for (int i : arr) {
            int t = i % k;
            if (t < 0) {
                t += k;
            }
            if (t != 0) {
                needCheckNum++;
                help[t]++;
            }
        }
        if (needCheckNum % 2 != 0) {
            return false;
        }
        for (int i = 1; i <= k/2; ++i) {
            if (i*2 != k) {
                if (help[i] != help[k-i]) {
                    return false;
                }
            } else if (help[i] % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    int64_t t = getCurrentTime();
    vector<int> input = {2,3,7,-9,4,4,7,3,2,10,8,15,2,1,-8,10,-5,10,-2,21,9,20,0,4,24,5,12,-10,8,9,18,13,-8,10,-4,-3,0,16,-4,8,14,15,-9,0,0,-6,11,-3,10,11,7,-1,-5,5,11,2,5,9,-2,8,9,-10,6,-2,7,8,3,0,-2,11};
    cout<<Solution::canArrange(input, 18);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

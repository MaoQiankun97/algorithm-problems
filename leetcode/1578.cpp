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
    gettimeofday(&tv, nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

//输入：s = "abaac", cost = [1,2,3,4,5]
//输出：3
//解释：删除字母 "a" 的成本为 3，然后得到 "abac"（字符串中相邻两个字母不相同）。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/minimum-deletion-cost-to-avoid-repeating-letters
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    static int minCost(string s, vector<int> &cost) {
        if (s.length() < 2) {
            return 0;
        }
        int result = 0;
        int pre = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[pre] == s[i]) {
                if (cost[pre] <= cost[i]) {
                    result += cost[pre];
                    pre = i;
                } else {
                    result += cost[i];
                }
            } else {
                pre = i;
            }
        }

        return result;
    }
};


int main() {
    int64_t t = getCurrentTime();
    vector<int> input = {1, 2, 3, 4, 1, 1, 2, 3, 4, 1, 1, 2, 3, 4, 1};
    cout << Solution::minCost("aaaaaaaaaaaaaaa", input);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

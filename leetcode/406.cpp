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

//输入:
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
//输出:
//[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    static vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        if (people.size() == 0) {
            return people;
        }
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> result = people;
        for (int i = result.size() - 1; i >= 0; --i) {
            // 后移
            if (result[i][1] != 0) {
                vector<int> temp = result[i];
                for (int j = i; j < (i + temp[1]); ++j) {
                    result[j] = result[j+1];
                }
                result[i + temp[1]] = temp;
            }
        }

        return result;
    }

private:
    static bool compare(vector<int> &a, vector<int> &b) {
//        int size = a.size();
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    }
};

int main() {
    int64_t t = getCurrentTime();
    vector<vector<int>> input = {
            {7, 0},
            {4, 4},
            {7, 1},
            {5, 0},
            {6, 1},
            {5, 2}
    };
    vector<vector<int>> output = Solution::reconstructQueue(input);
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i][0] << " " << output[i][1] << endl;
    }
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

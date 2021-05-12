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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> _temp;
        int i;
        for (i = 0; i < gas.size(); ++i) {
            _temp.push_back(gas[i]-cost[i]);
        }
        for (i = 0; i < _temp.size(); ++i) {
            int t = help(_temp, i);
            if (t != -1) {
                return t;
            }
        }
        return -1;
    }

private:
    int help(vector<int>& _temp, int start) {
        int i;
        int sum = 0;
        for (i = 0; i < _temp.size(); ++i) {
            int index = (start+i)%_temp.size();
            sum += _temp[index];
            if (sum<0) return -1;
        }
        return start;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout<<a.canCompleteCircuit(gas, cost);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

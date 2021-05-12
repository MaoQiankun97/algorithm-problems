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
    void search1(vector<int> candidates, int target, vector<int> temp, int start, vector<vector<int>>& result) {
        if (target < candidates[start]) return;
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] == target) {
                temp.push_back(i);
                vector<int> t_r;
                for (int j = 0; j < temp.size(); ++j) {
                    t_r.push_back(candidates[temp[j]]);
                }
                result.push_back(t_r);
            } else if (candidates[i] < target){
                vector<int> t = temp;
                t.push_back(i);
                search1(candidates, target-candidates[i], t, i, result);
            } else {
                return;
            }
        }
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n<=0)
            return {};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        search1(candidates, target, temp, 0, result);
        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {2, 3, 6, 7};
    vector<vector<int>> r = a.combinationSum(input, 7);
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}
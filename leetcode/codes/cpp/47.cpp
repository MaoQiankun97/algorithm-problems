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

    void swap(vector<int>& a, int i, int j) {
        if (i == j)
            return;
        a[i] = a[i]^a[j];
        a[j] = a[i]^a[j];
        a[i] = a[i]^a[j];
    }

    bool canSwap(vector<int> a, int i, int j) {
        for (int k = i; k < j; ++k) {
            if (a[k]==a[j]) return false;
        }
        return true;
    }

    void getResult(vector<int> nums, vector<vector<int>>& result, int begin) {
        if (begin>=nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            if (!canSwap(nums, begin, i)) continue;
            swap(nums, begin, i);
            getResult(nums, result, begin+1);
            swap(nums, begin, i);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size()<0) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        getResult(nums, result, 0);
        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {1, 2, 2, 1};
    vector<vector<int>> r = a.permuteUnique(input);
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<r.size()<<endl;
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}

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
private:
    int getIndex(vector<int> nums, int x) {
        int start = 0; int end = nums.size()-1;
        int mid;
        while (start<=end) {
            mid = (start+end)/2;
            if (nums[mid] == x) return mid;
            if (nums[mid] > x) end = mid-1;
            if (nums[mid] < x) start = mid+1;
        }

        return -1;
    }

    void getResult(vector<int>& nums, int k, vector<vector<int>> stack, vector<vector<int>>& result) {
        if (k>nums.size()) return;
        if (k == 1) {
            for (int i = 0; i < nums.size(); ++i) {
                stack.push_back({nums[i]});
                result.push_back({nums[i]});
            }
            getResult(nums, k+1, stack, result);
        } else {
            vector<vector<int>> newStack;
            vector<int> temp;
            for (int i = 0; i < stack.size(); ++i) {
                temp = stack[i];
                int index = getIndex(nums, temp[temp.size()-1]); // 取得temp中最大值在nums中的下标
                for (int j = index+1; j < nums.size(); ++j) {
                    vector<int> t = temp;
                    t.push_back(nums[j]);
                    newStack.push_back(t);
                    result.push_back(t);
                }
            }
            getResult(nums, k+1, newStack, result);
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return {{}};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.push_back({}); // 必有空子集
        vector<vector<int>> stack;
        getResult(nums, 1, stack, result);
        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {1, 2, 3};
    vector<vector<int>> r = a.subsets(input);
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

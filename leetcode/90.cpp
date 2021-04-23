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

struct Node {
    int val;
    int num;
    Node(int v, int n): val(v), num(n) {}
};

class Solution {
private:
    void getResult(int k, int start, int n, vector<int> temp, vector<Node> num_nodes, vector<vector<int>>& result) {
        if (k>n) return;
        if (start>n) return;
        for (int i = start; i < num_nodes.size(); ++i) {
            if (num_nodes[i].num>0) {
                temp.push_back(num_nodes[i].val);
                num_nodes[i].num--;
                result.push_back(temp);
                getResult(k+1, i, n, temp, num_nodes, result);
                temp.pop_back();
                num_nodes[i].num++;
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({}); // 必定存在空子集
        int n = nums.size();
        if (n == 0) return result;
        sort(nums.begin(), nums.end());
        vector<Node> num_nodes;
        for (int i = 0; i < nums.size(); ++i) {
            if (num_nodes.size() == 0 || num_nodes[num_nodes.size()-1].val != nums[i]) {
                Node t(nums[i], 1);
                num_nodes.push_back(t);
            }
            else {
                num_nodes[num_nodes.size()-1].num++;
            }
        }
        getResult(1, 0, n, {}, num_nodes, result);
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {1, 2, 2, 2};
    vector<vector<int>> r = a.subsetsWithDup(input);
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

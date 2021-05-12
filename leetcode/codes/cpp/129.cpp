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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<int> _nums;
        vector<vector<int>> nums;
        help(root, _nums, nums);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int k = 1; int _sum = 0;
            for (int j = nums[i].size()-1; j >= 0; j--) {
                _sum+=nums[i][j]*k;
                k*=10;
            }
            sum+=_sum;
        }
        return sum;
    }
private:
    void help(TreeNode* root, vector<int> _nums, vector<vector<int>>& nums) {
        if (root == NULL) return;
        _nums.push_back(root->val);
        if (root->left) help(root->left, _nums, nums);
        if (root->right) help(root->right, _nums, nums);
        if (!root->left && !root->right) {
            nums.push_back(_nums);
        }
    }
};
int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    TreeNode* root = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    root->left = b;
    root->right = c;
    cout<<a.sumNumbers(root);

    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <unordered_map>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root==NULL) return {};
        vector<vector<int>> result;
        vector<int> temp;
        getResult(root, sum, result, temp);
        return result;
    }
private:
    void getResult(TreeNode *root, int sum, vector<vector<int>>& result, vector<int> temp) {
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                temp.push_back(root->val);
                result.push_back(temp);
            }
            return;
        }
        temp.push_back(root->val);
        if (root->left!=NULL) getResult(root->left, sum-root->val, result, temp);
        if (root->right!=NULL) getResult(root->right, sum-root->val, result, temp);
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<int>> r = a.pathSum(new TreeNode(1), 1);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

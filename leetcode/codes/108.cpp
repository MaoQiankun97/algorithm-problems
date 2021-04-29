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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0) return NULL;
        return buildTree(nums, 0, nums.size()-1);
    }
private:
    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start>end) return NULL;
        int mid = start+((end-start)>>1);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, start, mid-1);
        root->right = buildTree(nums, mid+1, end);

        return root;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};
    TreeNode *root = a.sortedArrayToBST(input);

    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

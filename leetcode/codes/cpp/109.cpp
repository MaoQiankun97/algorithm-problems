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

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 简单转为数组 然后跟上一题一样处理 16ms
// class Solution {
// public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         if (head == NULL) return NULL;
//         vector<int> arr;
//         while (head!=NULL) {
//             arr.push_back(head->val);
//             head = head->next;
//         }
        
//         return buildTree(arr, 0, arr.size()-1);
//     }
// private:
//     TreeNode* buildTree(vector<int>& nums, int start, int end) {
//         if (start>end) return NULL;
//         int mid = start+((end-start)>>1);
//         TreeNode *root = new TreeNode(nums[mid]);
//         root->left = buildTree(nums, start, mid-1);
//         root->right = buildTree(nums, mid+1, end);

//         return root;
//     }
// };

// 不转为数组
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        return buildTree(head, NULL);
    }
private:
    TreeNode* buildTree(ListNode* start, ListNode* end) {
        if (start == end) return NULL;
        if (start->next == end) return new TreeNode(start->val);
        ListNode* slow = start;
        for (ListNode* i = start; i != end && i->next != end; i = i->next->next) {
            slow = slow->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        root->left = buildTree(start, slow);
        root->right = buildTree(slow->next, end);

        return root;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *head = new ListNode(0);
    for (int i = arr.size()-1; i >= 0; --i) {
        ListNode *b = new ListNode(arr[i]);
        b->next = head->next;
        head->next = b;

    }
    TreeNode *root = a.sortedListToBST(head->next);

    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

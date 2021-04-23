#include <iostream>
#include <algorithm>
#include <unordered_map>
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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// 题意为给一颗满二叉树 每个节点有额外的next指针，将该指针指向同一个层的右边的一个节点, 且只使用常数级的额外空间
// 如下所示：
/**     1 -> NULL
 *    /  \
 *   2 -> 3 -> NULL
 *  / \  / \
 * 4->5->6->7 -> NULL
 */
// 我的解法，需要的空间还是跟树的大小有关，不符合题意但可以ac
// class Solution {
// public:
//     void connect(TreeLinkNode *root) {
//         if (root == nullptr)
//             return;
//         queue<TreeLinkNode *> queue;
//         queue.push(root);
//         getResult(queue);
//     }
// private:
//     void getResult(queue<TreeLinkNode *>& queue) {
//         TreeLinkNode *pre = nullptr;
//         TreeLinkNode *t = nullptr;
//         int size = queue.size();
//         for (int i = 0; i < size; ++i) {
//             t = queue.front();
//             if (pre != nullptr) {
//                 pre->next = t;
//             }
//             if (t->left != nullptr) {
//                 queue.push(t->left);
//                 queue.push(t->right);
//             }
//             queue.pop();
//             pre = t;
//         }
//         if (pre!=nullptr) pre->next = nullptr;
//         if (queue.empty())
//             return;
//         getResult(queue);
//     }
// };

// 第一根柱子上的解法 amazing
class Solution {
public:
    void connect(TreeLinkNode *root) {
        helper(root, nullptr);
    }
private:
    void helper(TreeLinkNode *root, TreeLinkNode* next) {
        if(root==nullptr) return;
        root->next = next;
        helper(root->left, root->right);
        helper(root->right, next==nullptr?nullptr:next->left);
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

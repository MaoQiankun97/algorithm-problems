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

// 与上一题不同的是不一定是满二叉树，如下所示：
/**          1 -> NULL
 *         /  \
 *        2 -> 3 -> NULL
 *       / \    \
 *      4-> 5 -> 7 -> NULL
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        TreeLinkNode *p = root;
        TreeLinkNode *pre = nullptr;
        TreeLinkNode *first = nullptr;
        while (p!=nullptr) {
            if (pre == nullptr) {
                if (p->left != nullptr && p->right != nullptr) {
                    if (first == nullptr) first = p->left;
                    p->left->next = p->right;
                    pre = p->right;
                } else if (p->left != nullptr || p->right != nullptr) {
                    if (first == nullptr) first = p->left==nullptr?p->right:p->left;
                    pre = p->left==nullptr?p->right:p->left;
                }
            }
            else {
                if (p->left != nullptr && p->right != nullptr) {
                    pre->next = p->left;
                    p->left->next = p->right;
                    pre = p->right;
                } else if (p->left != nullptr || p->right != nullptr) {
                    pre->next = p->left==nullptr?p->right:p->left;
                    pre = pre->next;
                }
            }
            p = p->next;
        }
        connect(first);
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

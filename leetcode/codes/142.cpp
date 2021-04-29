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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* s = head;
        ListNode* f = head;
        ListNode* p = head;
        do {
            if (s == nullptr || f == nullptr) {
                return nullptr;
            }
            s = s->next;
            f = f->next;
            if (f == nullptr) {
                return nullptr;
            }
            f = f->next;
        } while (s != f);
        while (s != p) {
            s = s->next;
            p = p->next;
        }

        return p;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    ListNode *root, *b;
    root = (ListNode *)malloc(sizeof(ListNode));
    b = (ListNode *)malloc(sizeof(ListNode));
    root->val = 1;
    b->val = 2;
    root->next = b;
    b->next = root;
    ListNode* r = a.detectCycle(root);
    cout<<r->val;
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

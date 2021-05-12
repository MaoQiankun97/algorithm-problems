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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m>=n)
            return head;
        ListNode *r = head;
        ListNode *p = head;
        ListNode *pre_left = NULL;
        ListNode *pre_right = NULL;
        int i = 0;
        int j = 0;
        while (p!=NULL) {
            if (i < m-1) {
                pre_left = p;
                i++;
            }
            if (j < n-1) {
                pre_right = p;
                j++;
            }
            if (i==m-1&&j==n-1) break;
            p = p->next;
        }

        if (pre_left == NULL) {
            ListNode *right = pre_right->next;
            ListNode *t = right->next;
            if (pre_right == head) {
                right->next = head;
                head->next = t;
            } else {
                right->next = head->next;
                pre_right->next = head;
                head->next = t;
            }
            r = right;
        } else {
            ListNode *right = pre_right->next;
            ListNode *left = pre_left->next;
            ListNode *t = right->next;
            if (pre_right == left) {
                pre_left->next = right;
                right->next = left;
                left->next = t;
            } else {
                pre_left->next = right;
                right->next = left->next;
                pre_right->next = left;
                left->next = t;
            }
        }
        return reverseBetween(r, m+1, n-1);
//
//        return r;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    ListNode b(1);
    ListNode c(2);
    ListNode d(3);
    ListNode e(4);
    ListNode f(5);
    ListNode g(6);
    b.next = &c;
    c.next = &d; d.next = &e; e.next = &f; f.next = &g;
    ListNode *r = a.reverseBetween(&b, 3, 5);
    while (r!=NULL) {
        cout<<r->val<<"->";
        r = r->next;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

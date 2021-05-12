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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
            return NULL;
        ListNode *p = head;
        ListNode *r = NULL;
        ListNode *t = NULL;
        ListNode *m = NULL;
        ListNode *t_m = NULL;
        while (p!=NULL) {
            if (p->val < x) {
                if (r==NULL) {
                    r = p;
                    p = p->next;
                    r->next = NULL;
                    t = r;
                } else {
                    t->next = p;
                    p = p->next;
                    t = t->next;
                    t->next = NULL;
                }
            } else {
                if (m == NULL) {
                    m = p;
                    p = p->next;
                    m->next = NULL;
                    t_m = m;
                } else {
                    t_m->next = p;
                    p = p->next;
                    t_m = t_m->next;
                    t_m->next = NULL;
                }
            }
        }
        if (t!=NULL)
            t->next = m;
        else
            r = m;
        return r;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    ListNode b(1);
    ListNode c(4);
    ListNode d(3);
    ListNode e(2);
    ListNode f(5);
    ListNode g(2);
    b.next = &c; c.next = &d; d.next = &e; e.next = &f; f.next = &g;
    ListNode *r = a.partition(&b, 3);
    while (r!=NULL) {
        cout<<r->val<<"->";
        r = r->next;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

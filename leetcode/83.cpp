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
private:
    void getResult(ListNode *&p) {
        if (p==NULL || p->next == NULL)
            return;
        ListNode *t = p->next;
        while (t!=NULL && t->val == p->val) {
            t = t->next;
        }
        p->next = t;
        getResult(t);
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode *p = head;
        getResult(p);

        return p;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    ListNode root(1);
    ListNode b(1);
    ListNode c(2);
    ListNode d(2);
    root.next = &b;
    b.next = &c;
    c.next = &d;
    ListNode *r = a.deleteDuplicates(&root);
    while (r!=NULL) {
        cout<<r->val<<"->";
        r = r->next;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

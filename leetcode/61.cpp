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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k==0) return head;
        ListNode *p = head;
        int n = 1;

        vector<ListNode*> temp;
        temp.push_back(p);
        while (p->next!=NULL) {
            n++;
            p = p->next;
            temp.push_back(p);
        } // p指向链尾
        k %= n;
        if (k==0) return head;
        ListNode *r = head;
        temp[n-1-k]->next = NULL;
        p->next = r;
        r = temp[n-k];
        return r;
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
    ListNode* r = a.rotateRight(root, 5);
//    ListNode* r = root;
    while (r!=NULL) {
        cout<<r->val<<"->";
        r = r->next;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

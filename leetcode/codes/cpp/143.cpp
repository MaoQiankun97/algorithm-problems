#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;
        ListNode* l_last;
        while (f != nullptr) {
            l_last = s;
            s = s->next;
            f = f->next;
            if (f != nullptr) {
                f = f->next;
            }
        }
        l_last->next = nullptr;
        // 此时s为右链表的首节点
        s = reverseList(nullptr, s);
        ListNode *p = head;
        while (s != nullptr) {
            ListNode* _ = p->next;
            ListNode* __ = s->next;

            p->next = s;
            s->next = _;

            p = _;
            s = __;
        }
    }

private:
    ListNode* reverseList(ListNode* pre, ListNode* node) {
        if (node->next == nullptr) {
            node->next = pre;
            return node;
        }
        ListNode* res = reverseList(node, node->next);
        node->next = pre;

        return res;
    }
};


int main() {

//    ListNode* a1 = new ListNode(1);
//    ListNode* a2 = new ListNode(2);
//    ListNode* a3 = new ListNode(3);
//    ListNode* a4 = new ListNode(4);
////    ListNode* a5 = new ListNode(5);
//    a1->next = a2;
//    a2->next = a3;
//    a3->next = a4;
////    a4->next = a5;
//    Solution a;
//    a.reorderList(a1);

    int a, b;
    cout<<(a=2,b=5,a++,b++,a+b);

    return 0;
}
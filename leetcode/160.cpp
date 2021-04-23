#include "iostream"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        ListNode* p3 = headA;
        ListNode* p4 = headB;
        while (p1 != nullptr && p2!= nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 != nullptr) {
            while (p1 != nullptr) {
                p3 = p3->next;
                p1 = p1->next;
            }
        } else if (p2 != nullptr) {
            while ((p2 != nullptr)) {
                p4 = p4->next;
                p2 = p2->next;
            }
        }
        while (p3 != nullptr) {
            if (p3 == p4) {
                return p3;
            }
            p3 = p3->next;
            p4 = p4->next;
        }

        return nullptr;
    }
};
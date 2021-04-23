//
// Created by riddle on 2020/11/26.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct MyListNode {
    int val;
    MyListNode* pre;
    MyListNode* next;
    MyListNode(int x) : val(x), pre(NULL), next(NULL) {}
};

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> result;
        MyListNode* head = new MyListNode(-11111);
        MyListNode* tail;
        sort(deck.begin(), deck.end());
        MyListNode* p = new MyListNode(deck[deck.size() - 1]);
        head->next = p;
        p->pre = head;
        tail = p;
        for (int i = deck.size() - 2; i >= 0; --i) {
            if (tail != head->next) {
                MyListNode *t = tail->pre;
                tail->next = head->next;
                tail->next->pre = tail;
                tail->pre = head;
                head->next = tail;
                t->next = nullptr;
                if (t->pre == head) {
                    t->pre = head->next;
                }
                tail = t;
            }
            p = new MyListNode(deck[i]);
            p->next = head->next;
            p->next->pre = p;
            p->pre = head;
            head->next = p;
        }
        MyListNode* p1 = head->next;
        while (p1 != nullptr) {
            result.push_back(p1->val);
            p1 = p1->next;
        }

        return result;
    }
};

int main() {
    Solution a;
    vector<int> input = {17,13,11,2,3,5,7};
    vector<int> result = a.deckRevealedIncreasing(input);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }

    return 0;
}

#include <iostream>
#include <algorithm>
#include <sys/time.h>      //添加头文件
#define nullptr NULL
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv;
    gettimeofday(&tv, NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * result = new ListNode(0);
        ListNode * tail = result;
        int pre = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                pre += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                pre += l2->val;
                l2 = l2->next;
            }
            ListNode *p = new ListNode(pre % 10);
            pre /= 10;
            tail->next = p;
            tail = p;
        }
        if (pre != 0) {
            ListNode *p = new ListNode(pre);
            tail->next = p;
        }

        return result->next;
    }
};

int main() {
    int64_t t = getCurrentTime();
    ListNode * a1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode * a2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode * a3 = (ListNode *)malloc(sizeof(ListNode));
    ListNode * b1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode * b2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode * b3 = (ListNode *)malloc(sizeof(ListNode));
    a1->val = 2; a2->val = 4; a3->val = 3; a1->next = a2; a1->next->next = a3; a1->next->next->next = nullptr;
    b1->val = 5; b2->val = 6; b3->val = 4; b1->next = b2; b1->next->next = b3; b1->next->next->next = nullptr;
    ListNode* result = Solution().addTwoNumbers(a1, b1);
    while (result != nullptr) {
        cout<<result->val<<"->";
        result = result->next;
    }
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

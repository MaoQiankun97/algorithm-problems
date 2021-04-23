#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode *p = head;
        RandomListNode *r = NULL;
        RandomListNode *pr = NULL;
        while (p!=NULL) {
            if (r == NULL) {
                r = (RandomListNode *)malloc(sizeof(RandomListNode));
                r->label = p->label;
                r->next = NULL;
                r->random = NULL;
                pr = r;
            } else {
                RandomListNode *s = (RandomListNode *)malloc(sizeof(RandomListNode));
                s->label = p->label;
                s->next = NULL;
                s->random = NULL;
                pr->next = s;
                pr = pr->next;
            }
            p = p->next;
        }
        pr = r;
        p = head;
        while (p!=NULL) {
            RandomListNode *_t = p->random;
            if (_t!=NULL) {
                RandomListNode *__t = head;
                RandomListNode *___t = r;
                while (__t!=NULL) {
                    if (__t == _t) {
                        pr->random = ___t;
                        break;
                    }
                    __t = __t->next;
                    ___t = ___t->next;
                }
            }
            p = p->next;
            pr = pr->next;
        }
        return r;
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

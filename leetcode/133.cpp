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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        mp[node] = res;
        while(!q.empty()) {
            UndirectedGraphNode* t = q.front(); q.pop();
            for(UndirectedGraphNode* n: t->neighbors) {
                if (mp.find(n) == mp.end()) {
                    UndirectedGraphNode* cpy = new UndirectedGraphNode(n->label);
                    mp[n] = cpy;
                    q.push(n);
                }
                mp[t]->neighbors.push_back(mp[n]);
            }
        }

        return res;
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

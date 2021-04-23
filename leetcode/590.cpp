#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "set"
#include <sys/time.h>      //添加头文件

using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv, nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    static vector<int> postorder(Node* root) {
        vector<int> result;
        helper(root, result);

        return result;
    }

    static void helper(Node* root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        if (root->children.size() != 0) {
            for (auto& item: root->children) {
                helper(item, result);
            }
        }
        result.push_back(root->val);
    }
};

int main() {
    int64_t t = getCurrentTime();



    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

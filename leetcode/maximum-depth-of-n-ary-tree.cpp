#include "iostream"
#include "vector"

using namespace std;

// Definition for a Node.
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
    int maxDepth(Node* root) {
        return maxD(root);
    }

private:
    int maxD(Node* p) {
        if (p == nullptr) {
            return 0;
        }
        int r = 0;
        for (auto &item: p->children) {
            int t = maxD(item);
            if (t > r) {
                r = t;
            }
        }

        return r;
    }
};

int main() {

    return 0;
}

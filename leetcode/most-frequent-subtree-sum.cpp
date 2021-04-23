#include "iostream"
#include "vector"
#include "unordered_map"
#include "map"
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> _map;
        vector<pair<int, int>> helper;

        afterOrder(root, _map);
        auto it = _map.begin();
        while (it != _map.end()) {
            helper.emplace_back(it->first, it->second);
            it++;
        }

        sort(helper.begin(), helper.end(), compare);
        vector<int> result;
        int _t = -1;
        for (auto &item: helper) {
            if (_t == -1) {
                _t = item.second;
                result.push_back(item.first);
                continue;
            }
            if (item.second == _t) {
                result.push_back(item.first);
            } else {
                break;
            }
        }

        return result;
    }

private:

//    bool compare(pair<int, int> a, pair<int, int> b) {
//        return a.second > b.second;
//    }

    void afterOrder(TreeNode *root, unordered_map<int, int> &map) {
        if (root == nullptr) {
            return;
        }
        afterOrder(root->left, map);
        afterOrder(root->right, map);
        if (root->left != nullptr) {
            root->val = root->val + root->left->val;
        }
        if (root->right != nullptr) {
            root->val = root->val + root->right->val;
        }
        if (map.find(root->val) == map.end()) {
            map[root->val] = 1;
        } else {
            map[root->val]++;
        }
    }

};

int main() {
    auto root = new TreeNode(5);
    auto left = new TreeNode(2);
    auto righ = new TreeNode(-3);
    root->left = left;
    root->right = righ;
    Solution a;
    vector<int> result = a.findFrequentTreeSum(root);
    for (auto &item: result) {
        cout<<item<<" ";
    }

    return 0;
}

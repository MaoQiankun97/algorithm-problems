#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct Node {
    char c;
    int frequency;
};

bool compare(Node* a, Node* b) {
    return a->frequency > b->frequency;
}

int getNodeSize(Node* node) {
    if (node->frequency == 1) {
        return 1;
    }
    int bit = 0;
    while (node->frequency % 10 != 0) {
        bit++;
        node->frequency /= 10;
    }

    return bit + 1;
}

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        s += "_";
        char preChar = '_';
        int curFreq = 0;
        vector<Node*> helper;
        for (auto &item: s) {
            if (preChar == '_') {
                preChar = item;
                curFreq++;
            } else if (preChar == item) {
                curFreq++;
            } else {
                Node* n = new Node();
                n->frequency = curFreq;
                n->c = preChar;
                helper.push_back(n);
                curFreq = 1;
                preChar = item;
            }
        }

        sort(helper.begin(), helper.end(), compare);

        while (k > 0 && helper.size() > 0) {
            Node* node = helper[helper.size() - 1];
            if (node->frequency > k) {
                node->frequency -= k;
            } else {
                k -= node->frequency;
                helper.pop_back();
            }
        }

        int result = 0;
        for (auto &item: helper) {
            result += getNodeSize(item);
        }

        return result;
    }
};

int main() {
    Solution a;
    cout<<a.getLengthOfOptimalCompression("bbaabb ", 3);

    return 0;
}

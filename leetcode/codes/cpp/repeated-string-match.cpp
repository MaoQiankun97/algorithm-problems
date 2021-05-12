//
// Created by riddle on 2020/10/13.
//

#include "iostream"

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if (A.empty() || B.empty()) {
            return -1;
        }
        int ans = 1;
        string tmp = A;
        int sizeA = A.size();
        int sizeB = B.size();
        while (tmp.find(B) > tmp.size()) {
            if (tmp.size() > sizeA * 2 + sizeB) {
                return -1;
            }
            tmp += A;
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution a;

    cout<<a.repeatedStringMatch("abc", "cabcabcabca");
    // expect 5

    return 0;
}
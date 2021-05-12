//
// Created by riddle on 10/12/20.
//
#include "iostream"
#include "unordered_set"

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        int n = (1 << k);
        int r = k;
        int pre = strToInt(s, 0, k);
        unordered_set<int> help;
        help.insert(pre);

        int _ = (1 << k) - 1;

        while (r < s.size()) {
            int cur = (( pre<<1) + (s[r] - '0')) & _;
            help.insert(cur);
            r++;
            pre = cur;
            if (help.size() == n) {
                return true;
            }
        }

        return false;

    }

private:
    int strToInt(string s, int l, int r) {
        int result = 0b0;
        for (int i = l; i < r; ++i) {
            result <<= 1;
            result += s[i] - '0';
        }

        return result;
    }
};

int main() {
    Solution a;

    cout << a.hasAllCodes("00110110", 2);

    return 0;
}
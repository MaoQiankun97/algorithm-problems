//
// Created by riddle on 10/12/20.
//
#include "iostream"
#include "stack"
#include "vector"

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        vector<int> nums;
        vector<string> strs;
        int bracketFlag = 0;
        nums.push_back(1);
        strs.push_back("");
        int _num = 0;
        for (auto &item: s) {
            if ('0' <= item && item <= '9') {
                _num = _num * 10 + item - '0';
            } else if (item == '[') {
                bracketFlag++;
                strs.push_back("");
                nums.push_back(_num);
                _num = 0;
            } else if (item == ']') {
                string t = strs[bracketFlag];
                int num = nums[bracketFlag];
                strs.pop_back();
                nums.pop_back();
                bracketFlag--;
                for (int i = 0; i < num; ++i) {
                    strs[bracketFlag] = strs[bracketFlag] + t;
                }
            } else {
                strs[bracketFlag] = strs[bracketFlag] + item;
            }
        }

        return strs[0];
    }
};

int main() {
    Solution a;
//    2[ab]e3[cd]ef
// "3[z]2[2[y]pq4[2[jk]e1[f]]]ef"
    cout << a.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    // expect: ababecdcdcdefacceacce
    //         ababecdcdcdefacceacce

    return 0;
}
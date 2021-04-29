//
// Created by riddle on 2020/10/13.
//
#include "iostream"
#include "unordered_set"
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int _t = n;
        unordered_set<int> visited;

        while (true) {
            int __t = 0;
            while (_t > 0) {
                __t += ((_t % 10) * (_t % 10));
                _t /= 10;
            }
            _t = __t;
            if (_t == 1) {
                return true;
            }
            if (visited.find(_t) != visited.end()) {
                return false;
            }
            visited.insert(_t);
        }
    }
};

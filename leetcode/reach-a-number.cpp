//
// Created by riddle on 2020/10/14.
//
#include "iostream"

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        if (target == 0) {
            return 0;
        }
        if (target < 0) {
            target = - target;
        }
        int k = 1;
        int s = 0;
        while (true) {
            s += k;
            if (s >= target && (s - target) % 2 == 0) {
                return k;
            }
            k++;
        }
    }
};

// 起点0 终点target 第i次走i步, 允许向前或向后走, 求问至少走几次能从0到target
int main() {
    Solution a;
    cout << a.reachNumber(5);

    return 0;
}

//
// Created by riddle on 2020/12/8.
//
#include "iostream"
#include "vector"
#include <stdlib.h>

using namespace std;


class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        backtrack(list, S, S.length(), 0, 0, 0);
        return list;
    }

    bool backtrack(vector<int> &list, string S, int length, int index, long long sum, int prev) {
        if (index == length) {
            return list.size() >= 3;
        }
        long long curr = 0;
        for (int i = index; i < length; i++) {
            // 如果当前数不是0却以0开头, 不符合题意
            if (i > index && S[index] == '0') {
                break;
            }
            // 计算i后移之后的curr值, 如果大于INT_MAX不符合题意
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX) {
                break;
            }
            // list的元素大于两个的时候需要开始判断是否满足斐波那契数列性质，即cur是否等于sum
            if (list.size() >= 2) {
                if (curr < sum) {
                    continue;
                } else if (curr > sum) {
                    break;
                }
            }
            // 如果curr == sum, 说明暂时满足斐波那契数列性质, 压入list中, 开始后续的判断
            list.push_back(curr);
            if (backtrack(list, S, length, i + 1, prev + curr, curr)) {
                return true;
            }
            // 截取curr不能满足后续所有地方都满足斐波那契数列性质, pop并继续
            list.pop_back();
        }
        return false;
    }
};


int main() {
    Solution a;
    vector<int> r = a.splitIntoFibonacci("1102358");
    for (auto &item: r) {
        cout << item << " ";
    }

    return 0;
}
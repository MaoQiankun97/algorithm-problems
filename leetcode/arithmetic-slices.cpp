//
// Created by riddle on 2020/11/24.
//
#include "iostream"
#include "vector"

using namespace std;

//[1, 2, 3, 4]
// 1 2 3
// 2 3 4
// 1 2 3 4

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int count = 0;
        int sum = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                count++;
            } else {
                sum += (count + 1) * (count) / 2;
                count = 0;
            }
        }
        return sum += count * (count + 1) / 2;
    }
};

int main() {


    return 0;
}
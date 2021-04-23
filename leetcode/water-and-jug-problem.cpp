//
// Created by riddle on 2020/10/12.
//
#include "iostream"
#include "cmath"

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) {
            return false;
        }
        if (z == 0) {
            return true;
        }
        if (x == 0) {
            return z == y;
        }
        if (y == 0) {
            return z == x;
        }

        if (z % gcd(x, y) == 0) {
            return true;
        }

        return false;
    }

private:
    int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
};

int main() {
    Solution a;
    cout << a.canMeasureWater(13, 11, 1);
    return 0;
}
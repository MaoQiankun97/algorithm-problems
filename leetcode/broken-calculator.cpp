//
// Created by riddle on 2020/11/24.
//
#include "iostream"

using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int d_f = 0;
        while ((X << d_f) < Y) {
            d_f++;
        }
        int de_f = (X << d_f) - Y;
        int i = 0;
        int dedef = 0;
        while (d_f > i && de_f > 0) {
            while (de_f >= (1 << (d_f - i))) {
                de_f -= (1 << (d_f - i));
                dedef++;
            }
            i++;
        }

        return d_f + de_f + dedef;
    }
};

int main() {
    Solution a;
    cout<<a.brokenCalc(13, 1413643123);

    return 0;
}
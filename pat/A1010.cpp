//
// Created by mqk on 2020/4/8.
//

#include "iostream"
#include "unordered_map"

using namespace std;

unordered_map<char, long> help = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'a', 10},
        {'b', 11},
        {'c', 12},
        {'d', 13},
        {'e', 14},
        {'f', 15},
        {'g', 16},
        {'h', 17},
        {'i', 18},
        {'j', 19},
        {'k', 20},
        {'l', 21},
        {'m', 22},
        {'n', 23},
        {'o', 24},
        {'p', 25},
        {'q', 26},
        {'r', 27},
        {'s', 28},
        {'t', 29},
        {'u', 30},
        {'v', 31},
        {'w', 32},
        {'x', 33},
        {'y', 34},
        {'z', 35}
};

long getRadixByChar(char c) {
//    if ('0' <= c && c <= '9') {
//        return c - '0';
//    } else if ('a' <= c && c <= 'z') {
//        return c - 'a' + 10;
//    } else {
//        return -1;
//    }
    return help[c];
}

int main() {
    string n1, n2;
    long tag, radix;
    while (cin >> n1 >> n2 >> tag >> radix) {
        // 根据tag和radix将对应的数转为十进制.
        string one;
        string other_one;
        if (tag == 1) {
            one = n1;
            other_one = n2;
        } else {
            other_one = n1;
            one = n2;
        }
        long sum_one = 0;
        for (const auto _c : one) {
            sum_one *= radix;
            sum_one += getRadixByChar(_c);
        }
        // 获取另外一个数的最小进制数.
        long _radix = -1;
        for (const auto _c : other_one) {
            _radix = max(_radix, getRadixByChar(_c) + 1);
        }
        if (other_one.length() <= 1) {
            for (long i = _radix; i <= 36; ++i) {
                long sum_other_one = 0;
                for (const auto _c : other_one) {
                    sum_other_one *= i;
                    sum_other_one += getRadixByChar(_c);
                }
                if (sum_other_one > sum_one) {
                    cout << "Impossible" << endl;
                    break;
                } else if (sum_other_one == sum_one) {
                    cout << i << endl;
                    break;
                }
//            else if (i == sum_one + 1) {
////                getRadixByChar('z') + 1
//                cout<<"Impossible"<<endl;
//            }
            }
        } else {
            // 二分法 radix最小为_radix 最大为sum_one, 因为当other_one位数大于1时, 高位必有不为0的数, 如果radix > sum_one则other_one必大于sum_one
            long min = _radix;
            long max = sum_one;
            long mid = (min + max) / 2;
            while (min <= max) {
                long sum_other_one = 0;
                for (const auto _c : other_one) {
                    sum_other_one *= mid;
                    sum_other_one += getRadixByChar(_c);
                }
                if (sum_other_one > sum_one || sum_other_one < 0) {
                    max = mid - 1;
                    mid = (min + max) / 2;
                } else if (sum_other_one == sum_one) {
                    cout << mid << endl;
                    break;
                } else {
                    min = mid + 1;
                    mid = (min + max) / 2;
                }
            }
            if (min > max) {
                cout << "Impossible" << endl;
            }
        }
    }

    return 0;
}
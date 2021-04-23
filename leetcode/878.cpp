//
// Created by riddle on 10/11/20.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        long long _gcd = qGCD(A, B);
        A /= _gcd;
        B /= _gcd;

        long _result = 0;
        vector<int> help;
        for (int i = 1, j = 1; i < B || j <= A;) {
            if (A*i < B*j) {
                help.push_back(A*i++);
            } else {
                help.push_back(B*j++);
            }
        }
//        for (int i = 1; i < B; ++i) {
//            help.push_back(A*i);
//        }
//        for (int i = 1; i <= A; ++i) {
//            help.push_back(B*i);
//        }
//        sort(help.begin(), help.end());
        int hsize = help.size();
        int n = N / hsize;
        int m = N % hsize;
        _result = (_result + (long long) help[hsize - 1] * n) % 1000000007;
        if (m != 0) {
            _result = (_result + help[m - 1]) % 1000000007;
        }

        return (_result * _gcd) % 1000000007;
    }
    // 999860007
private:

    int qGCD(int a, int b)
    {
        if(a == 0) return b;
        if(b == 0) return a;
        if(!(a & 1) && !(b & 1)) // a % 2 == 0 && b % 2 == 0;
            return qGCD(a >> 1, b >> 1) << 1;
        else if(!(b & 1))
            return qGCD(a, b >> 1);
        else if(!(a & 1))
            return qGCD(a >> 1, b);
        else
            return qGCD(abs(a - b), min(a, b));
    }

};


int main() {
    Solution a;
    cout<<a.nthMagicalNumber(1000000000
    ,39999
    ,40000);
    return 0;
}


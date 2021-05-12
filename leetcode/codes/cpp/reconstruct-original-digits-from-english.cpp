//
// Created by riddle on 2020/11/24.
//
#include "ostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> c_s(26, 0);
        vector<char> r_t;
        for (auto &it: s) {
            c_s[it - 'a']++;
        }
        // 0
        if (c_s['z' - 'a'] > 0) {
            int t = c_s['z' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('0');
            }
            c_s['z' - 'a'] -= t;
            c_s['e' - 'a'] -= t;
            c_s['r' - 'a'] -= t;
            c_s['o' - 'a'] -= t;
        }
        // 2
        if (c_s['w' - 'a'] > 0) {
            int t = c_s['w' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('2');
            }
            c_s['t' - 'a'] -= t;
            c_s['w' - 'a'] -= t;
            c_s['o' - 'a'] -= t;
        }
        // 4
        if (c_s['u' - 'a'] > 0) {
            int t = c_s['u' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('4');
            }
            c_s['u' - 'a'] -= t;
            c_s['f' - 'a'] -= t;
            c_s['o' - 'a'] -= t;
            c_s['r' - 'a'] -= t;
        }
        // 6
        if (c_s['x' - 'a'] > 0) {
            int t = c_s['x' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('6');
            }
            c_s['x' - 'a'] -= t;
            c_s['s' - 'a'] -= t;
            c_s['i' - 'a'] -= t;
        }
        // 8
        if (c_s['g' - 'a'] > 0) {
            int t = c_s['g' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('8');
            }
            c_s['e' - 'a'] -= t;
            c_s['i' - 'a'] -= t;
            c_s['g' - 'a'] -= t;
            c_s['h' - 'a'] -= t;
            c_s['t' - 'a'] -= t;
        }

        // 1
        if (c_s['o' - 'a'] > 0) {
            int t = c_s['o' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('1');
            }
            c_s['o' - 'a'] -= t;
            c_s['n' - 'a'] -= t;
            c_s['e' - 'a'] -= t;
        }

        // 3
        if (c_s['r' - 'a'] > 0) {
            int t = c_s['r' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('3');
            }
            c_s['t' - 'a'] -= t;
            c_s['h' - 'a'] -= t;
            c_s['r' - 'a'] -= t;
            c_s['e' - 'a'] -= t;
            c_s['e' - 'a'] -= t;
        }

        // 5
        if (c_s['f' - 'a'] > 0) {
            int t = c_s['f' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('5');
            }
            c_s['f' - 'a'] -= t;
            c_s['i' - 'a'] -= t;
            c_s['v' - 'a'] -= t;
            c_s['e' - 'a'] -= t;
        }
        // 7
        if (c_s['s' - 'a'] > 0) {
            int t = c_s['s' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('7');
            }
            c_s['s' - 'a'] -= t;
            c_s['e' - 'a'] -= t;
            c_s['v' - 'a'] -= t;
            c_s['e' - 'a'] -= t;
            c_s['n' - 'a'] -= t;
        }
        // 9
        if (c_s['i' - 'a'] > 0) {
            int t = c_s['i' - 'a'];
            for (int i  = 0; i < t; ++i) {
                r_t.push_back('9');
            }
            c_s['n' - 'a'] -= t;
            c_s['i' - 'a'] -= t;
            c_s['e' - 'a'] -= t;
            c_s['n' - 'a'] -= t;
        }

        sort(r_t.begin(), r_t.end());
        string result = "";
        for (int i = 0; i < r_t.size(); ++i) {
            result += r_t[i];
        }

        return result;
    }
};
// zero                   z
// two                    w
// four                   u
// six                    x
// eight                  g

// one                    o
// three                  r
// five                   f
// seven                  s

// nine






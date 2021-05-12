//
// Created by riddle on 2020/10/14.
//
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> result;
        if (A.size() == 0) {
            return result;
        }

        vector<int> frequency(26, 0);
        for (int i = 0; i < A[0].size(); ++i) {
            frequency[A[0][i] - 'a']++;
        }

        for (int i = 1; i < A.size(); ++i) {
            vector<int> _frequency(26, 0);
            for (int j = 0; j < A[i].size(); ++j) {
                _frequency[A[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                if (_frequency[j] < frequency[j]) {
                    frequency[j] = _frequency[j];
                }
            }
        }

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < frequency[i]; ++j) {
                string _s = "";
                result.emplace_back(_s + (char)('a' + i));
            }
        }

        return result;
    }
};

int  main() {
    Solution a;
    vector<string> input = {
            "cabcde",
            "abcc",
            "bccd",
            "ccde"
    };
    vector<string> result =  a.commonChars(input);
    for (auto &item: result) {
        cout<<item<<" ";
    }

    return 0;
}
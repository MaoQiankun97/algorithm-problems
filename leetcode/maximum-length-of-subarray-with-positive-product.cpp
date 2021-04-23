//
// Created by riddle on 2020/11/26.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
    return a.size() > b.size();
}

class Solution {
public:
    int getMaxLen(vector<int> &nums) {
        vector<vector<int>> help;
        vector<int> t;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (t.size() > 0) {
                    help.push_back(t);
                }
                t = vector<int>();
            } else {
                t.push_back(nums[i]);
            }
        }
        if (t.size() > 0) {
            help.push_back(t);
        }
        sort(help.begin(), help.end(), compare);
        int r = 0;
        for (auto &item: help) {
            if (item.size() < r) {
                continue;
            }
            bool f = true;
            int l_neg = 99999999;
            int r_neg = -1;
            for (int i = 0; i < item.size(); ++i) {
                if (item[i] < 0) {
                    f = !f;
                    l_neg = min(l_neg, i);
                    r_neg = max(r_neg, i);
                }
            }
            if (l_neg == 99999999) {
                l_neg = -1;
            }
            if (r_neg == -1) {
                r_neg = item.size();
            }
            if (f) {
                if (item.size() > r) {
                    r = item.size();
                }
            } else {
                int _t = r_neg > (item.size() - l_neg - 1) ? r_neg : (item.size() - l_neg - 1);
                if (_t > r) {
                    r = _t;
                }
            }
        }

        return r;
    }
};

class Solution1 {
public:
    int getMaxLen(vector<int> &nums) {
        int length = nums.size();
        vector<int> positive(length), negative(length);
        if (nums[0] > 0) {
            positive[0] = 1;
        } else if (nums[0] < 0) {
            negative[0] = 1;
        }
        int maxLength = positive[0];
        for (int i = 1; i < length; ++i) {
            if (nums[i] > 0) {
                positive[i] = positive[i - 1] + 1;
                negative[i] = negative[i - 1] > 0 ? negative[i - 1] + 1 : 0;
            } else if (nums[i] < 0) {
                positive[i] = negative[i - 1] > 0 ? negative[i - 1] + 1 : 0;
                negative[i] = positive[i - 1] + 1;
            } else {
                positive[i] = 0;
                negative[i] = 0;
            }
            if (positive[i] > maxLength) {
                maxLength = positive[i];
            }
        }
        return maxLength;
    }
};


int main() {
    Solution1 a;
    vector<int> input = {-1, 2, -51};
    cout << a.getMaxLen(input);

    return 0;
}


//
// Created by riddle on 2020/10/8.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    static int evalRPN(vector<string>& tokens) {
        vector<int> nums;

        for(auto& item: tokens) {
            if (item == "+" || item == "-" || item == "*" || item == "/") {
                int a = nums[nums.size() - 1];
                int b = nums[nums.size() - 2];
                nums.pop_back();
                nums.pop_back();
                if (item == "+") {
                    nums.push_back(a + b);
                } else if (item == "-") {
                    nums.push_back(b - a);
                } else if (item == "*") {
                    nums.push_back(a * b);
                } else if (item == "/") {
                    nums.push_back(b / a);
                }
            } else {
                nums.push_back(stringToInt(item));
            }
        }

        return nums[0];
    }

private:

    static int stringToInt(string s) {
        int result = 0;
        for (int i = s.size() - 1, j = 1; i >= 0; --i, j*=10) {
            if (s[i] == '-') {
                result *= -1;
            } else {
                result += (s[i] - '0') * j;
            }
        }

        return result;
    }
};

int main()
{
    vector<string> input = {"4", "13", "5", "/", "+"};
    cout<<Solution::evalRPN(input);
    cout<<endl;
    return 0;
}

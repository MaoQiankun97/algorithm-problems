#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    static string reverseWords(string s) {
        string _ = "";
        vector<string> resultHelper;
        for (auto &item: s) {
            if (item == ' ') {
                if (_ != "") {
                    resultHelper.push_back(_);
                    _ = "";
                }
            } else {
                _ += item;
            }
        }
        if (_ != "") {
            resultHelper.push_back(_);
        }
        string result = "";
        for (int i = resultHelper.size()-1; i >= 0; --i) {
            result += resultHelper[i];
            if (i != 0) {
                result += " ";
            }
        }

        return result;
    }
};

int main()
{
    cout<<Solution::reverseWords("the sky is blue");
    cout<<endl;
    return 0;
}

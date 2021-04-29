#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> char_index(26, -1);

        int result = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (char_index[s[i] - 'a'] != -1) {
                int t = i - char_index[s[i] - 'a'] - 1;
                if (t > result) {
                    result = t;
                }
            } else {
                char_index[s[i] - 'a'] = i;
            }
        }

        return result;
    }
};


int main() {
    Solution a;

    cout<<a.maxLengthBetweenEqualCharacters("cabbac");

    return 0;
}

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        if (num == 0) {
            return result;
        }
        result[1] = 1;

        for (int i = 2; i <= num; ++i) {
            result[i] = result[i>>1] + (i & 0b1);
        }

        return result;
    }
};

int main() {
    Solution a;
    vector<int> result = a.countBits(100);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<" ";
    }

    return 0;
}
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        if (threshold == 0) {
            return vector<bool>(queries.size(), true);
        }
        vector<bool> result;
        for (int i = 0; i < queries.size(); ++i) {
            if (gcd(queries[i][0], queries[i][1]) <= threshold)  {
                result.push_back(false);
            } else {
                result.push_back(true);
            }
        }

        return result;
    }

private:
    int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
};

int main() {
    Solution a;
    vector<vector<int>> input = {
            {16, 9}
    };
    a.areConnected(0, 3, input);

    return 0;
}

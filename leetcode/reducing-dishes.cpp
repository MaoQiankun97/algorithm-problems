#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int> &satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> helper(satisfaction);
        for (int i = 1; i < helper.size(); ++i) {
            helper[i] += helper[i-1];
        }

        int n = satisfaction.size();
        int k = 1;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (satisfaction[i] + helper[n-1]-helper[i] < 0) {
                continue;
            } else {
                result += satisfaction[i] * k++;
            }
        }


        return result;
    }
};

int main() {
    vector<int> input = {
            -7, -2, -1, 0, 3, 5
    };
    Solution a;

    cout << a.maxSatisfaction(input);

    return 0;
}
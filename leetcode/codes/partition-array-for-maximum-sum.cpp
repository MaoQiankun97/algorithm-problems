#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        if (arr.empty()) return 0;

        vector<int> dp(arr.size() + 1);
        dp[0] = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int max = -1;
            int MAX = -1;
            for (int j = i; j >= 0 && i - j < k; --j) {
                if (MAX < arr[j]) {
                    MAX = arr[j];
                }
                int t = dp[j] + (i-j + 1) * MAX;
                if (t > max) {
                    max = t;
                }
            }
            dp[i+1] = max;
        }

        return dp[arr.size()];
    }
};


 int main() {
    vector<int> input = {1,15,7,9,2,5,10};
    int k = 3;

    Solution a;
    cout<<a.maxSumAfterPartitioning(input, k);

    return 0;
}
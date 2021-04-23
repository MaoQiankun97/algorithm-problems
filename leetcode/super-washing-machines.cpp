#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        if (machines.size() < 2) {
            return 0;
        }
        int n = machines.size();
        int sum = 0;
        for (auto &item: machines) {
            sum += item;
        }
        if (sum % n != 0) {
            return -1;
        }
        int avg = sum / n;
        for (auto &item: machines) {
            item -= avg;
        }
        int _max_abs = 0;
        int _cur_sum = 0;
        int result = -1;
        for (int i = 0; i < n; ++i) {
            _cur_sum += machines[i];
            if (abs(_cur_sum) > _max_abs) {
                _max_abs = abs(_cur_sum);
            }
            result = max(result, max(_max_abs, machines[i]));
        }

        return result;
    }
};

int main() {
    Solution a;
    vector<int> input = {0,0,11,5};

    cout << a.findMinMoves(input);

    return 0;
}
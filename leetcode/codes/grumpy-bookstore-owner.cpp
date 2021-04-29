#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        for (int & i : grumpy) {
            i = !i;
        }
        int result = 0;
        for (int i = 0; i < customers.size(); ++i) {
            result += customers[i] * (i < X ? 1 : grumpy[i]);
        }
        int t = result;
        for (int i = X; i < customers.size(); ++i) {
            if (!grumpy[i]) {
                t += customers[i];
            }
            if (!grumpy[i-X]) {
                t -= customers[i-X];
            }
            if (t > result) {
                result = t;
            }
        }

        return result;
    }
};

int main () {
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy =    {0,1,0,1,0,1,0,1};
    int X = 3;

    cout<<Solution::maxSatisfied(customers, grumpy, X);

    return 0;
}
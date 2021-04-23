#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }
        int cur_buy = prices[0];
        int cur_sell = -1;
        int pre_buy = -1;
        int pre_sell = -1;
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < cur_buy) {
                cur_buy = prices[i];
                continue;
            }
            if (i + 1 < prices.size() && prices[i+1] > prices[i]) {
                continue;
            }
            // 如果当前价格大于上次售出价格 撤销上次交易 改为在这次进行
            if (pre_sell != -1 && prices[i] > pre_sell) {
                result -= pre_sell - pre_buy - fee;
                cur_buy = pre_buy;

                cur_sell = prices[i];
                result += cur_sell - cur_buy - fee;
                pre_sell = cur_sell;
                cur_buy = cur_sell;
            }
            if (prices[i] - fee > cur_buy) {
                // 如果上次售出价跟本次购买价差价不到交易手续费 需要撤销上一次的交易
                if (pre_buy != -1 && pre_sell - cur_buy < fee) {
                    result -= pre_sell - pre_buy - fee;
                    cur_buy = pre_buy;
                }

                cur_sell = prices[i];
                result += cur_sell - cur_buy - fee;
                pre_buy = cur_buy;
                pre_sell = cur_sell;
                cur_buy = cur_sell;
            }
        }

        return result;
    }
};

int main() {
    vector<int> input = {
            1917,1973,2197,3659,3099,4220,2402
    };


    Solution a;

    cout << a.maxProfit(input, 1231);
    // expect 1085
    // 722

    return 0;
}
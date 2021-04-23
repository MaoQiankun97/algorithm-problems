//
// Created by mqk on 2020/4/1.
//
#include "iostream"
using namespace std;

int main() {
    int n; // 数量.
    while (cin>>n) {
        int arr[n];
        bool all_negative = true;
        // 输入.
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
            if (arr[i] >= 0) {
                all_negative = false;
            }
        }
        if (all_negative) {
            cout<<0<<" "<<arr[0]<<" "<<arr[n-1]<<endl;
            continue;
        }
        // dp[i]表示截至到i的最大子序列值.
        // dp[i+1] = max(dp[i] + arr[i], arr[i])
        int dp[n];
        dp[0] = arr[0];
        int _max = dp[0]; int _max_index = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i-1] + arr[i], arr[i]);
            if (dp[i] > _max) {
                _max = dp[i];
                _max_index = i;
            }
        }

        int left_index = _max_index;
        do {
            --left_index;
        } while (left_index >= 0 && dp[left_index] >= 0);
        if (left_index < _max_index) {
            left_index++;
        }

        cout<<dp[_max_index]<<" "<<(arr[left_index])<<" "<<(arr[_max_index])<<endl;
    }
    return 0;
}
//10
//-10 1 2 3 4 -5 -23 3 7 -21
//
//expect: 10 1 4

//6
//-2 11 -4 13 -5 -2
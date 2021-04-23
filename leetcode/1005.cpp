#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sys/time.h>      //添加头文件

using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv, nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
public:
    static int largestSumAfterKNegations(vector<int>& A, int K) {
        int negativeNumberCount = 0;
        for (int i : A) {
            if (i < 0) {
                negativeNumberCount++;
            }
        }
        sort(A.begin(), A.end());
        if (negativeNumberCount == 0) {
            A[0] = -A[0];
        } else {
            if (K <= negativeNumberCount) {
                for (int i = 0; i < K; ++i) {
                    A[i] = -A[i];
                }
            } else {
                for (int i = 0; i < negativeNumberCount; ++i) {
                    A[i] = -A[i];
                }
                K -= negativeNumberCount;
                if (K % 2 == 1) {
                    if (negativeNumberCount == A.size()) {
                        A[negativeNumberCount - 1] = -A[negativeNumberCount - 1];
                    } else {
                        if (A[negativeNumberCount - 1] < A[negativeNumberCount]) {
                            A[negativeNumberCount - 1] = -A[negativeNumberCount - 1];
                        } else {
                            A[negativeNumberCount] = -A[negativeNumberCount];
                        }
                    }
                }
            }
        }

        // 求和
        int sum = 0;
        for (int i : A) {
            sum+=i;
        }

        return sum;
    }
};

int main() {
    int64_t t = getCurrentTime();
    vector<int> input = {4, 2, 3};
    cout << Solution::largestSumAfterKNegations(input, 1);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

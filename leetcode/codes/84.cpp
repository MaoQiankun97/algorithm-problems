#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv;
    gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

//
//class Solution {
//public:
//    int largestRectangleArea(vector<int>& heights) {
//        int min_h = INT32_MAX;
//        int max = 0;
//        for (int i = 0; i < heights.size(); ++i) {
//            for (int j = i; j < heights.size(); ++j) {
//                if (heights[j]<min_h) min_h = heights[j];
//                if (min_h*(j-i+1)>max) max = min_h*(j-i+1);
//            }
//            min_h = INT32_MAX;
//        }
//        return max;
//    }
//};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> stack; int top = -1;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            if (top == -1 || heights[stack[top]] < heights[i]) {
                stack.push_back(i);
                ++top;
            } else {
                int cur = stack[top]; top--; stack.pop_back();
                res = max(res, heights[cur] * (top==-1?i:(i-stack[top]-1)));
                --i;
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {2, 1, 5, 6, 2, 3};
    cout<<a.largestRectangleArea(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

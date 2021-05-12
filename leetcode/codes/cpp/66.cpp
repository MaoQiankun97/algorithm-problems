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

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int t = 1; int temp;
        int i;
        for (i = digits.size()-1; i >= 0 ; --i) {
            temp = digits[i];
            digits[i] = (temp+t)%10;
            t = (temp+t)/10;
            if (t==0) return digits;
        }

        // t!=0
        vector<int> r;
        r.push_back(t);
        for (i = 0; i < digits.size(); ++i) {
            r.push_back(digits[i]);
        }
        return r;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {9, 9, 9};
    vector<int> r = a.plusOne(input);
    for (int i = 0; i < r.size(); ++i) {
        cout<<r[i]<<" ";
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
    string addBinary(string a, string b) {
        if (a.length()<b.length()) return addBinary(b, a); // 使a的长度不小于b的长度

        int i, j; int temp = 0; char t;
        for (i = a.length()-1, j = b.length()-1; i >= 0 ; --i, --j) {
            if (j>=0) {
                t = a[i];
                a[i] = (a[i]+b[j]+temp-'0'-'0')%2+'0';
                temp = (t+b[j]+temp-'0'-'0')/2;
            } else {
                t = a[i];
                a[i] = (a[i]+temp-'0')%2+'0';
                temp = (t+temp-'0')/2;
            }
        }
        char stack[10]; int top = -1;
        while (temp!=0) {
            ++top;
            stack[top] = (temp%2+'0');
            temp/=2;
        }
        string s;
        while (top!=-1) {
            s+=stack[top];
            top--;
        }
        s+=a;
        return s;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.addBinary("111", "1");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

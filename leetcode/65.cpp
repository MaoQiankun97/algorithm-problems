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
private:
    bool isNumberBef(string s, int start, int end) {
        // 0.1 || 1 || -1 || -0.1
        // 若'-'出现在非第一个位置或出现多次或'.'出现一次以上时返回false, 'start=end'
        if (s[start] == '-'||s[start] == '+') start++;
        if (start>end) return false;
        for (int i = start; i <= end; ++i) {
            if (s[i]>'9' || s[i]<'0') return false;
        }

        return true;
    }
    bool isNumberPre(string s, int start, int end) {
        // 0.1 || 1 || -1 || -0.1
        // 若'-'出现在非第一个位置或出现多次或'.'出现一次以上时返回false, 'start=end'
        int do_index = -1;
        if (s[start] == '-'||s[start] == '+') start++;
        if (start>end) return false;
        for (int i = start; i <= end; ++i) {
            if (s[i] == '-' || s[i] == '+') return false;
            if (s[i] == '.' && do_index != -1) return false;
            if (s[i] == '.' && do_index == -1) do_index = i;
            if (s[i] != '.' && (s[i]>'9' || s[i]<'0')) return false;
        }
        if (start==end && do_index != -1) return false;

        return true;
    }
public:
    bool isNumber(string s) {
        int start = 0; int end = s.length()-1; int e = -1;
        // start标识着字符串第一个非空格字符的下标
        // end标识着字符串最后一个非空格字符的下标
        // 若start>end 则返回false
        while (s[start] == ' ') start++;
        while (s[end] == ' ') end--;
        if (start>end) return false;

        // 查找字符'e'所在的下标, 若e出现一次以上则返回false
        for (int i = start+1; i <= end-1; ++i) {
            if (s[i]=='e' && e!=-1) return false;
            if (s[i]=='e' && e==-1) e = i;
        }
        if (e!=-1) {
            return isNumberPre(s, start, e-1)&&isNumberBef(s, e+1, end);
        } else
            return isNumberPre(s, start, end);
    }
};
int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.isNumber("+.9");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

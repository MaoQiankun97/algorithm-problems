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
    string getRes(string s, int t, int n) {
        if (t==n) return s;
        string temp;
        int i;
        char j;
        i = 0, j = '1';
        while (i < s.length()) {
            while (i+1 < s.length() && s[i] == s[i+1]) {
                i++;
                j++;
            }
            temp += j;
            temp += s[i];
            i++;
            j='1';
        }
        return getRes(temp, t+1, n);
    }

public:
    string countAndSay(int n) {
        int t = 1;
        string a = "1";
        string r = getRes(a, t, n);
        return r;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.countAndSay(30);
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}
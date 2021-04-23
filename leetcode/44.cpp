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
//    bool isMatch(const char *s, const char *p) {
//        const char* star=NULL;
//        const char* ss=s;
//        while (*s){
//            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
//
//            if (*p=='*'){star=p++; ss=s;continue;}
//
//            if (star){ p = star+1; s=++ss;continue;}
//
//            return false;
//        }
//
//        while (*p=='*'){p++;}
//
//        return !*p;
//    }
    bool isMatch(string s, string p) {
        int p_t = -1;
        int s_t = 0;
        int i, j;
        i = 0; j = 0;
        while (i<s.length()) {
            if (s[i]==p[j] || p[j]=='?') {
                i++;
                j++;
                continue;
            }

            if (p[j]=='*') {
                p_t = j;
                s_t = i;
                j++;
                continue;
            }

            if (p_t != -1) {
                j = p_t+1;
                i = ++s_t;
                continue;
            }

            return false;
        }

        while (j<p.length()&&p[j]=='*') j++;
        return j==p.length();
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {1,1};
    cout<<a.isMatch("holder", "h*r");
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}

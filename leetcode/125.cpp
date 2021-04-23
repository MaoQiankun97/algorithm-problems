#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
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
    bool isPalindrome(string s) {
        int i, j;
        i = 0;
        j = s.length()-1;
        while (i<j) {
            while (i<j && !(
                      (s[i]<='9'&&s[i]>='0') ||
                      (s[i]<='z'&&s[i]>='a') ||
                      (s[i]<='Z'&&s[i]>='A')
                    ))
                i++;
            while (i<j && !(
                    (s[j]<='9'&&s[j]>='0') ||
                    (s[j]<='z'&&s[j]>='a') ||
                    (s[j]<='Z'&&s[j]>='A')
            ))
                j--;
            if (s[i]==s[j] ||
                    ((s[i]<='Z'&&s[i]>='A') || (s[i]<='z'&&s[i]>='a')) &&
                    ((s[j]<='Z'&&s[j]>='A') || (s[j]<='z'&&s[j]>='a')) &&
                    max(s[i], s[j])-min(s[i], s[j])==('a'-'A')) {
                i++;
                j--;
                continue;
            }
            return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();

//    cout<<a.isPalindrome("0P")
    cout<<a.isPalindrome("A man, a plan, a canal: Panama");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

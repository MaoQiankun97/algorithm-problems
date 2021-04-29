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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    bool check(string s) {
        if (s.length()>3 || s.length() <=0) return false;
        int t = 0;
        int h = 1;
        for (int i = s.length()-1; i >= 0; --i) {
            t+=((s[i]-'0')*h);
            h*=10;
        }
        return t>=0&&t<256;
    }

    void getResult(string s, int start, string temp, string add, int k, vector<string>& result) {
        if (start>=s.length())
            return;
        if (k>=4)
            return;
        add+=s[start];
        if (check(add)) {
            if (start == s.length()-1 && k == 3) {
                result.push_back(temp+add);
                return;
            }
            if (add[0] != '0')
                getResult(s, start+1, temp, add, k, result);
            temp = temp+add+".";
            getResult(s, start+1, temp, "", k+1, result);
        } else {
            return;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12)
            return {};
        vector<string> result;
        getResult(s, 0, "", "", 0, result);
        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<string> r = a.restoreIpAddresses("25525511135");
    for (int i = 0; i < r.size(); ++i) {
        cout<<r[i]<<endl;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

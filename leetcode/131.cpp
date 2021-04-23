#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
    vector<vector<string>> partition(string s) {
        if (s.length()==0) return {};
        vector<vector<string>> ans;
        vector<string> temp;
        getAns(s, 0, ans, temp, 1);
        return ans;
    }
private:
    void getAns(string s, int begin, vector<vector<string>>& ans, vector<string> temp, int k) {
        if (begin == s.length()) {
            ans.push_back(temp); 
            return;
        }
        if (begin+k>s.length()) return;
        string t = s.substr(begin, k);
        getAns(s, begin, ans, temp, k+1);
        if (!check(t))
            return;
        temp.push_back(t);
        getAns(s, begin+k, ans, temp, 1);
    }

    bool check(string s) {
        int i = 0, j = s.length()-1;
        for (; i < j; ++i, --j) {
            if (s[i]!=s[j]) 
                return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<string>> r = a.partition("efe");
    for (vector<string> v: r) {
        for (string s: v) 
            cout<<s<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
    int bth(string s) {
        int r = 0;
        int x = 1;
        for (int i = s.length()-1; i >= 0; --i) {
            r+=(s[i]-'0')*x;
            x*=2;
        }
        return r;
    }

    vector<int> getResult(vector<string> queue) {
        vector<int> r;
        for (int i = 0; i < queue.size(); ++i) {
            r.push_back(bth(queue[i]));
        }
        return r;
    }
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        if (n == 1) return {0, 1};
        int i = 1;
        vector<string> queue;
        queue.push_back("0");
        queue.push_back("1");
        while (i < n) {
            vector<string> queue2;
            for (int j = 0; j < queue.size(); ++j) {
                string t = queue[j]+"0";
                queue2.push_back(t);
            }
            for (int j = queue.size()-1; j >= 0; --j) {
                string t = queue[j]+"1";
                queue2.push_back(t);
            }
            i++;
            queue = queue2;
        }
        vector<int> r = getResult(queue);
        return r;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> r = a.grayCode(2);
    for (int i = 0; i < r.size(); ++i) {
        cout<<r[i]<<" ";
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
    void getResult(string path, vector<string>& queue, int start) {
        while (start<path.size() && path[start] == '/') {
            start++;
        }
        if (start>=path.size())
            return;
        string t = "/";
        while (start < path.size() && path[start] != '/') {
            t+=path[start];
            start++;
        }
        if (t=="/.") ; // do nothing
        else if (t=="/..") {
            if (queue.size()>0)
                queue.pop_back();
        }
        else {
            queue.push_back(t);
        }
        getResult(path, queue, start);
    }
public:
    string simplifyPath(string path) {
        vector<string> queue;
        getResult(path, queue, 0);
        string result = "";
        for (int i = 0; i < queue.size(); ++i) {
            result+=queue[i];
        }
        if (result == "") return "/";
        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.simplifyPath("/a//b////c/d//././/..");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

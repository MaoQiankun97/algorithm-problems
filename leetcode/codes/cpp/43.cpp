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

    string multiplySC(string num1, char c, int i) {
        if (c == '0') return "0";
        int top = num1.length()-1;
        int c1 = c-'0';
        vector<int> r;
        int t = 0;
        string s = "";
        while (top!=-1) {
            r.push_back(((num1[top]-'0')*c1+t)%10);
            t = ((num1[top]-'0')*c1+t)/10;
            top--;
        }
        if (t!=0) r.push_back(t);
        for (int j = r.size()-1; j >= 0; --j) {
            s+=(r[j]+'0');
        }
        for (int k = 0; k < i; ++k) {
            s+='0';
        }
        return s;
    }

    string addTwoString(string s1, string s2) {
        int top1 = s1.length()-1;
        int top2 = s2.length()-1;
        if (top1<top2) return addTwoString(s2, s1);
        int t = 0; string s;
        vector<int> a;
        while (top1!=-1) {
            if (top2 <= -1) {
                a.push_back((s1[top1]-'0'+t)%10);
                t = (s1[top1]-'0'+t)/10;
            } else {
                a.push_back((s1[top1]+s2[top2]-'0'-'0'+t)%10);
                t = (s1[top1]+s2[top2]-'0'-'0'+t)/10;
            }
            top1--;
            top2--;
        }
        if (t!=0) a.push_back(t);
        for (int j = a.size()-1; j >= 0; --j) {
            s+=(a[j]+'0');
        }
        return s;
    }

    string add(vector<string> as) {
        if (as.size() <= 0) return "";
        for (int i = as.size()-1; i > 0; --i) {
            as[i-1] = addTwoString(as[i], as[i-1]);
        }
        return as[0];
    }

public:
    string multiply(string num1, string num2) {
        string t1 = num1; string t2 = num2;
        int top1 = num1.length()-1;
        int top2 = num2.length()-1;
        if (top1<top2) return multiply(num2, num1);
        int i = 0;
        vector<string> needAdd;
        while (top2 != -1) {
            needAdd.push_back(multiplySC(num1, num2[top2], i));
            i++;
            top2--;
        }
        return add(needAdd);
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {1,1};
    cout<<a.multiply("12345678", "0");
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}

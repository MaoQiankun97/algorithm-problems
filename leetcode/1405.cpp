#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv,nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


class Solution {
public:
    static string longestDiverseString(int a, int b, int c) {
        return help(a, b, c, 'd');
    }

private:
    static string help(int a, int b, int c, char pre) {
        // 123
        int sum = a + b + c;
        if (sum == 0) {
            return "";
        }
        if (a == sum) {
            if (pre == 'a') {
                return "";
            } else {
                return a > 1 ? "aa" : "a";
            }
        } else if (b == sum) {
            if (pre == 'b') {
                return "";
            } else {
                return b > 1 ? "bb" : "b";
            }
        } else if (c == sum) {
            if (pre == 'c') {
                return "";
            } else {
                return c > 1 ? "cc" : "c";
            }
        }

        int max_char = max(max(a, b), c);
        if (a == max_char) {
            if (pre == 'a') {
                int max_bc = max(b, c);
                if (b == max_bc) {
//                    if (b >= 2) {
//                        return "bb" + help(a, b - 2, c, 'b');
//                    } else {
                        return "b" + help(a, b - 1, c, 'b');
//                    }
                } else {
//                    if (c >= 2) {
//                        return "cc" + help(a, b, c-2, 'c');
//                    } else {
                        return "c" + help(a, b, c-1, 'c');
//                    }
                }
            } else {
                if (a >= 2) {
                    return "aa" + help(a - 2, b, c, 'a');
                } else {
                    return "a" + help(a - 1, b, c, 'a');
                }
            }
        } else if (b == max_char) {
            if (pre == 'b') {
                int max_ac = max(a, c);
                if (a == max_ac) {
//                    if (a >= 2) {
//                        return "aa" + help(a - 2, b, c, 'a');
//                    } else {
                        return "a" + help(a - 1, b, c, 'a');
//                    }
                } else {
//                    if (c >= 2) {
//                        return "cc" + help(a, b, c-2, 'c');
//                    } else {
                        return "c" + help(a, b, c-1, 'c');
//                    }
                }
            } else {
                if (b >= 2) {
                    return "bb" + help(a, b - 2, c, 'b');
                } else {
                    return "b" + help(a, b - 1, c, 'b');
                }
            }
        } else {
            if (pre == 'c') {
                int max_ab = max(a, b);
                if (a == max_ab) {
//                    if (a >= 2) {
//                        return "aa" + help(a - 2, b, c, 'a');
//                    } else {
                        return "a" + help(a - 1, b, c, 'a');
//                    }
                } else {
//                    if (b >= 2) {
//                        return "bb" + help(a, b - 2, c, 'b');
//                    } else {
                        return "b" + help(a, b - 1, c, 'b');
//                    }
                }
            } else {
                if (c >= 2) {
                    return "cc" + help(a, b, c-2, 'c');
                } else {
                    return "c" + help(a, b, c-1, 'c');
                }
            }
        }
    }
};

int main()
{
    int64_t t = getCurrentTime();
    cout<<Solution::longestDiverseString(0, 8, 11);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

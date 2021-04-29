#include <iostream>
#include <algorithm>
#include <sys/time.h>      //添加头文件
#include <map>
#include <unordered_map>

#define nullptr NULL
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv;
    gettimeofday(&tv, NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
    unordered_map<char, int> char_index;
private:
    void initWhenRepeat(const string &s, int start, int end) {
        char_index.clear();
        for (int i = start; i <= end; ++i) {
            char_index[s[i]] = i;
        }
    }

    bool hasRepeat(char a, int i) {
        bool result = false;
        if (char_index.count(a)) {
            result = true;
        } else {
            char_index[a] = i;
        }

        return result;
    }

public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size == 0) return 0;
        int dp[size];
        dp[0] = 1;
        int max = 1;
        char_index[s[0]] = 0;
        for (int i = 1; i < size; ++i) {
            if (hasRepeat(s[i], i)) {
                int start = char_index[s[i]] + 1;
                int end = i;
                initWhenRepeat(s, start, end);
                dp[i] = end - start + 1;
            } else {
                dp[i] = dp[i-1] + 1;
            }
            if (dp[i] > max) {
                max = dp[i];
            }
        }

        return max;
    }
};

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int array[95] = {0,};
        int max = 0;
        int temp = 0;
        int window_start = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(!array[s[i]-' '])
            {
                array[s[i]-' '] = i+1;
                temp++;
            }
            else
            {
                if(temp>max)
                    max = temp;

                if(array[s[i]-' ']>window_start)
                    window_start = array[s[i]-' '];

                temp = i + 1 - window_start;
                array[s[i]-' '] = i+1;
            }
        }
        if(temp>max)
            return temp;
        return max;
    }
};

int main() {
    int64_t t = getCurrentTime();
    string input = "abac";
    cout << Solution().lengthOfLongestSubstring(input);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}

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
    void getResult(vector<string> words, vector<string>& result, int start, int maxWidth) {
        if (start >= words.size()) return;
        if (words[start].length()>maxWidth)
            return;
        int i; int length = 0;
        for (i = start; i < words.size(); ++i) {
            length += words[i].length();
            if (i-start>0) {
                length+=1;
            }
            if (length > maxWidth) {
                length = length-words[i].length()-1;
                break;
            }
        }

        string temp = "";
        int word_num = i-start;
        int space_sum = maxWidth-length+word_num-1;
        if (i >= words.size()) {
            int j;
            for (j = start; j < i; ++j) {
                temp+=words[j];
                if (space_sum>0) {
                    temp += " ";
                    space_sum--;
                }
            }
            for (int k = 0; k < space_sum; ++k) {
                temp+=" ";
            }
            result.push_back(temp);
            return;
        }
        if (word_num>1) {
            int space_front = space_sum%(word_num-1);
            int space_num = space_sum/(word_num-1);
            int j;
            for (j = start; j < i - 1; ++j) {
                temp += words[j];
                for (int k = 0; k < space_num; ++k) {
                    temp += " ";
                    if (space_front != 0) {
                        temp += " ";
                        space_front--;
                    }
                }
            }
            temp+=words[j];
            result.push_back(temp);
        } else {
            temp+=words[start];
            for (int k = 0; k < space_sum; ++k) {
                temp+=" ";
            }
            result.push_back(temp);
        }

        getResult(words, result, i, maxWidth);
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        getResult(words, result, 0, maxWidth);
        return result;
    }
};
int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<string> input = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> r = a.fullJustify(input, 16);
    for (int i = 0; i < r.size(); ++i) {
        cout<<r[i]<<endl;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

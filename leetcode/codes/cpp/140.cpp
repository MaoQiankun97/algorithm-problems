#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;
//Input:
//s = "catsanddog"
//wordDict = ["cat", "cats", "and", "sand", "dog"]
//Output:
//[
//"cats and dog",
//"cat sand dog"
//]

//"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
//["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv,nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}
class Solution {
    unordered_map<string, vector<string>> m;

    static vector<string> combine(const string& word, vector<string> prev) {
        for (auto & i : prev) {
            i += " " + word;
        }
        return prev;
    }
    vector<string> wordBreak(const string& s, unordered_set<string> &dict) {
        if (m.count(s)) return m[s];
        vector<string> result;
        if (dict.count(s)) {
            result.push_back(s);
        }
        for (int i = s.size() - 1; i > 0; --i) {
            string word = s.substr(i);
            if (dict.count(word)) {
                vector<string> prev = combine(word, wordBreak(s.substr(0, i), dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        m[s] = result;
        return result;
    }
    /* s = 'catsand' dict = ['cat', 'cats', 'sand', 'and']
     * 1. s = 'catsand' word == 'and' 时进入 combine('and', (2.1) wordBreak('cats', dict)); 此时result为空 m['catsand']为空
     *   2.1 word == 'ats’ 时跳出 (2.1) 回到 (1.) 此时result有一个值'cats' 结束时 m['cats'] = ['cats']
     * 1. s = 'catsand' word == 'sand‘ 时进入 combine('sand', (2.2) wordBreak('cat', dict)); 此时result为combine('end', (2.1) wordBreak('cats', dict))的结果: 'cats and', m['catsand']为空;
     *   2.2 word == 'at' 时跳出(2.2) 回到 (1.) 此时result有一个值'cat' 结束时 m['cat'] = ['cat']
     * 1. s = 'catsand' word == 'atsand' 时结束循环 此时result插入一个值: combine('sand', (2.2) wordBreak('cat', dict))的结果: 'cat sand', m['catsand']为空;
     * 1. m['catsand'] = result = ['cats and', 'cat sand'] 直接return
     */
    /*
     * s = 'aabaa' dict = ['a', 'aa']
     * 1. s = 'aabaa' word = 'a' 时进入 combine('a', (2.1) wordBreak('aaba', dict));
     *   2.1 s = 'aaba' word = 'a' 时进入 combine('a', (3.1) wordBreak('aab', dict));
     *     3.1 s = 'aab' word = 'ab'时跳出循环 result 为空 m['aab']为空数组
     *   2.1 s = ''aaba word = 'aba’ 时跳出循环 result 为空 m['aaba']为空数组
     * 1. s = 'aabaa' word = 'aa' 时进入 combine('aa', (2.2) wordBreak('aab’, dict));
     *   2.2 s = 'aab' 直接return m['aab'] 即空数组
     * 1. s = 'aabaa’ word = 'abaa' 时跳出循环 result为空
     */

public:
    vector<string> wordBreak(const string& s, vector<string> &dict) {
        unordered_set<string> _dict;
        for (const auto & i : dict) {
            _dict.insert(i);
        }
        return wordBreak(s, _dict);
    }
};


int main()
{
    int64_t t = getCurrentTime();
//    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string s = "catsand";
    // 1. s: catsand  步骤: d -> nd -> and 此时and在dict中存在, 开始递归
    //  1.1 s: cats  步骤 s -> ts -> ats -> cats 此时 cats在dict中存在
//    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result = Solution().wordBreak(s, wordDict);
    cout<<"["<<endl;
    for (const auto& _s: result) {
        cout<<"\""<<_s<<"\""<<endl;
    }
    cout<<"]"<<endl;
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

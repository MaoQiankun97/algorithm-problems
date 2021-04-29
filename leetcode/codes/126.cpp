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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& _wordList) {
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        unordered_set<string> wordList;
        for (string w: _wordList) wordList.insert(w);
        int n = wordList.size();
        wordList.insert(endWord);
        if (n!=wordList.size()) return {};
        n = wordList.size();
        paths.push({beginWord});
        int level = 1;
        int minLevel = INT32_MAX;
        unordered_set<string> visited;

        while (!paths.empty()) {
            vector<string> path = paths.front(); paths.pop();
            if (path.size() > level) {
                for (string w: visited) wordList.erase(w);
                visited.clear();
                if (path.size() > minLevel) break;
                else level = path.size();
            }
            string last = path.back();

            for (int i = 0; i < last.size(); ++i) {
                string _new = last;
                for (char c = 'a'; c <= 'z'; c++) {
                    _new[i] = c;
                    if (wordList.find(_new) != wordList.end()) {
                        vector<string> newpath = path;
                        newpath.push_back(_new);
                        visited.insert(_new);
                        if (_new == endWord) {
                            minLevel = level;
                            ans.push_back(newpath);
                        }
                        else
                            paths.push(newpath);
                    }
                }
            }
        }


        return ans;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();

    vector<string> input = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> r = a.findLadders("hit", "cog", input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

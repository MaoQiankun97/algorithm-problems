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
    bool search(vector<vector<char>> board, int i, int j, string word, int begin, vector<vector<bool>>& flag) {
        if (begin >= word.size()) return true;
        if (i-1 >= 0 && !flag[i-1][j] && board[i-1][j] == word[begin]) {
            flag[i-1][j] = true;
            if (search(board, i-1, j, word, begin+1, flag))
                return true;
            flag[i-1][j] = false;
        }
        if (i+1 < board.size() && !flag[i+1][j] && board[i+1][j] == word[begin]) {
            flag[i+1][j] = true;
            if (search(board, i+1, j, word, begin+1, flag))
                return true;
            flag[i+1][j] = false;
        }
        if (j-1 >= 0 && !flag[i][j-1] && board[i][j-1] == word[begin]) {
            flag[i][j-1] = true;
            if (search(board, i, j-1, word, begin+1, flag))
                return true;
            flag[i][j-1] = false;
        }
        if (j+1 < board[i].size() && !flag[i][j+1] && board[i][j+1] == word[begin]) {
            flag[i][j+1] = true;
            if (search(board, i, j+1, word, begin+1, flag))
                return true;
            flag[i][j+1] = false;
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        if (board.size() == 0 || board[0].size() == 0) return false;
        vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    flag[i][j] = true;
                    if (search(board, i, j, word, 1, flag))
                        return true;
                    flag[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<char>> input = {
            {'a', 'b', 'c', 'e'},
            {'s', 'f', 'c', 's'},
            {'a', 'd', 'e', 'e'}
    };
    cout<<a.exist(input, "abfe");
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

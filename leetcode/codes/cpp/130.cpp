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
    void solve(vector<vector<char>>& board) {
        if (board.size()==0) return;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<vector<bool>> temp(board.size(), vector<bool>(board[0].size(), false));
        vector<vector<bool>> __t = temp;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (!visited[i][j] && board[i][j]=='O') {
                    if (help(board, i, j, visited, temp))
                        for (int k = 0; k < temp.size(); ++k)
                            for (int l = 0; l < temp[k].size(); ++l) 
                                if (temp[k][l])
                                   board[k][l] = 'X';
                    temp = __t;
                    
                }   
                else visited[i][j] = true;
            }
        }
    }
private:
    bool help(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, vector<vector<bool>>& temp) {
        if (i<0||i>=board.size()) return false;
        if (j<0||j>=board[i].size()) return false;
        if (temp[i][j]) return true;
        visited[i][j] = true;
        temp[i][j] = true;
        if (!check(board, i+1, j)) 
            if (!help(board, i+1, j, visited, temp)) {
                return false;
            }
        if (!check(board, i-1, j)) 
            if (!help(board, i-1, j, visited, temp)) {
                return false;
            }
        if (!check(board, i, j+1)) 
            if (!help(board, i, j+1, visited, temp)) {
                return false;
            }
        if (!check(board, i, j-1)) 
            if (!help(board, i, j-1, visited, temp)) {
                return false;
            }
        return true;
    }

    bool check(vector<vector<char>>& board, int i, int j) {
        if (i<0||i>=board.size()) return false;
        if (j<0||j>=board[i].size()) return false;
        return board[i][j]=='X';
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<vector<char>> input = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    // vector<vector<char>> input = {
    //     {'X','O','O','X','X','X','O','X','O','O'},
    //     {'X','O','X','X','X','X','X','X','X','X'},
    //     {'X','X','X','X','O','X','X','X','X','X'},
    //     {'X','O','X','X','X','O','X','X','X','O'},
    //     {'O','X','X','X','O','X','O','X','O','X'},
    //     {'X','X','O','X','X','O','O','X','X','X'},
    //     {'O','X','X','O','O','X','O','X','X','O'},
    //     {'O','X','X','X','X','X','O','X','X','X'},
    //     {'X','O','O','X','X','O','X','X','O','O'},
    //     {'X','X','X','O','O','X','O','X','X','O'}
    // };
    a.solve(input);
    for (vector<char> a: input) {
        for (char c: a) {
            cout<<c<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}

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
public:
    bool isRowAndColumnValid(vector<vector<char>>& board) {
        int d1 = 0, t1 = 0, d2 = 0, t2 = 0;
        bool flag1[9], flag2[9];
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < 9; ++k) {
                flag1[k] = false;
                flag2[k] = false;
            }
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    d1++;
                } else if (!flag1[board[i][j]-'1']) {
                        t1++;
                        flag1[board[i][j]-'1'] = true;
                }
                if ((d1+t1) != j+1) return false;

                if (board[j][i] == '.') {
                    d2++;
                } else if (!flag2[board[j][i]-'1']) {
                    t2++;
                    flag2[board[j][i]-'1'] = true;
                }
                if ((d2+t2)!=j+1) return false;
            }
            d1 = 0;
            t1 = 0;
            d2 = 0;
            t2 = 0;
        }
        return true;
    }
    
    bool isSubBoxValid(vector<vector<char>>& board) {
        int d = 0, t = 0;
        bool flag[9];
        for (int k = 0; k < 9; ++k) {
            flag[k] = false;
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (board[3*i+k][3*j+l] == '.') {
                            d++;
                        } else if (!flag[board[3*i+k][3*j+l]-'1']) {
                            t++;
                            flag[board[3*i+k][3*j+l]-'1'] = true;
                        }
                        if ((d+t) != k*3+l+1) return false;
                    }
                }
                for (int k = 0; k < 9; ++k) {
                    flag[k] = false;
                }
                d = 0;
                t = 0;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return isRowAndColumnValid(board)&&isSubBoxValid(board);
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
//    vector<vector<char >> input = {
//            {'8','3','.','.','7','.','.','.','.'},
//            {'6','.','.','1','9','5','.','.','.'},
//            {'.','9','8','.','.','.','.','6','.'},
//            {'8','.','.','.','6','.','.','.','3'},
//            {'4','.','.','8','.','3','.','.','1'},
//            {'7','.','.','.','2','.','.','.','6'},
//            {'.','6','.','.','.','.','2','8','.'},
//            {'.','.','.','4','1','9','.','.','5'},
//            {'.','.','.','.','8','.','.','7','9'}
//    };
    vector<vector<char >> input = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    cout<<a.isValidSudoku(input);
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}
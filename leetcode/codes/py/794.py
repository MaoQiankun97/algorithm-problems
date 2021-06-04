from typing import List


class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        x_num = 0
        o_num = 0
        is_x_win = False
        is_o_win = False
        for i in range(3):
            for j in range(3):
                c = board[i][j]
                isx = False
                iso = False
                if c == 'X':
                    x_num += 1
                    isx = True
                elif c == 'O':
                    o_num += 1
                    iso = True
                if (isx or iso) and i == 2:
                    if board[i-1][j] == board[i-2][j] and board[i-2][j] == c:
                        if isx:
                            is_x_win = True
                        else:
                            is_o_win = True
                    if j == 0:
                        if board[i-1][1] == board[i-2][2] and board[i-2][2] == c:
                            if isx:
                                is_x_win = True
                            else:
                                is_o_win = True
                    if j == 2:
                        if board[i-1][1] == board[i-2][0] and  board[i-2][0] == c:
                            if isx:
                                is_x_win = True
                            else:
                                is_o_win = True
                if (isx or iso) and  j == 2:
                    if board[i][j-1] == board[i][j-2] and board[i][j-2] == c:
                        if isx:
                            is_x_win = True
                        else:
                            is_o_win = True

        if x_num < o_num:
            return False

        if x_num - o_num > 1:
            return False

        if is_x_win:
            return x_num > o_num

        if is_o_win:
            return x_num == o_num

        return True

a = Solution()
print(a.validTicTacToe(["XO ", "   ", "X  "]))
from typing import List


# ["1","0","1","0","0"]
# ["1","0","1","1","1"]
# ["1","1","1","1","1"]
# ["1","0","1","1","0"]
# 4
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0

        # dp[i][j] 表示到下标i-1 j-1是连续多少个1
        dp = []
        r = 0
        for i in range(len(matrix) + 1):
            dp.append([0] * (len(matrix[0]) + 1))

        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == '1':
                    if dp[i][j] > 0 and dp[i + 1][j] > 0 and dp[i][j + 1] > 0:
                        dp[i + 1][j + 1] = 1 + min(dp[i][j], dp[i + 1][j], dp[i][j + 1])
                    else:
                        dp[i + 1][j + 1] = 1
                else:
                    dp[i + 1][j + 1] = 0

                if dp[i + 1][j + 1] > r:
                    r = dp[i + 1][j + 1]

        return r ** 2


a = Solution()
print(a.maximalSquare(
    [["1", "0", "1", "1", "0"],
     ["1", "1", "1", "1", "1"],
     ["1", "1", "1", "0", "1"],
     ["1", "1", "1", "1", "1"]]
))

# 664. 奇怪的打印机
# 有台奇怪的打印机有以下两个特殊要求：
#
# 打印机每次只能打印由 同一个字符 组成的序列。
# 每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
# 给你一个字符串 s ，你的任务是计算这个打印机打印它需要的最少打印次数。
#
#
# 示例 1：
#
# 输入：s = "aaabbb"
# 输出：2
# 解释：首先打印 "aaa" 然后打印 "bbb"。
# 示例 2：
#
# 输入：s = "aba"
# 输出：2
# 解释：首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
#
#
# 提示：
#
# 1 <= s.length <= 100
# s 由小写英文字母组成
class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = []
        for i in range(n):
            dp.append([1] * n)

        i = n - 1
        #   a b a
        #   1 1 1
        #   1 1 1
        #   1 1 1
        #1. 1 1 1
        #   1 1 1
        #   1 1 1
        #2. 1 1 1
        #   1 1 2
        #   1 1 1
        #3. 1 2 2
        #   1 1 2
        #   1 1 1
        while i >= 0:
            j = i + 1
            while j < n:
                if s[i] == s[j]:
                    dp[i][j] = dp[i][j - 1]
                else:
                    minn = 99999999999999999999999
                    k = i
                    while k < j:
                        minn = min(minn, dp[i][k] + dp[k + 1][j])
                        k += 1
                    dp[i][j] = minn
                j += 1
            i -= 1

        return dp[0][n - 1]

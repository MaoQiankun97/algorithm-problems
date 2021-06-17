class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # 最长公共子序列问题
        dp = []
        dp.append([0] * (len(word2) + 1))
        for i in range(len(word1)):
            dp.append([0] * (len(word2) + 1))
        for i in range(len(word1)):
            for j in range(len(word2)):
                if word1[i] == word2[j]:
                    dp[i + 1][j + 1] = dp[i][j] + 1
                else:
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j])

        return len(word1) + len(word2) - 2 * dp[len(word1)][len(word2)]


a = Solution()

print(a.minDistance('eat', 'tea'))

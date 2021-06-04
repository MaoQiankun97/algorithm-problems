class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # 丑数序列 1*2、1*3、1*5、1*2*2、1*2*3、1*2*2*2、1*3*3、 1*2*5、1*2*2*3、1*3*5、1*2*3*3、1*2*2*5
        # 2 3 4 5 6 8 9 10 12 15 18 20....
        dp = []
        dp.append(1)
        p2, p3, p5 = 0, 0, 0
        while n > 1:
            next = min(dp[p2] * 2, dp[p3] * 3, dp[p5] * 5)
            if next == dp[p2] * 2:
                p2 += 1
            if next == dp[p3] * 3:
                p3 += 1
            if next == dp[p5] * 5:
                p5 += 1
            dp.append(next)
            n -= 1

        return dp[len(dp) - 1]

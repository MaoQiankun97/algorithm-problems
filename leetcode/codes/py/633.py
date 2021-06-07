import math


class Solution:
    def isPrim(self, c: int):
        sq = int(math.sqrt(c))
        i = 2
        while i <= sq:
            if c % i == 0:
                return False
            i += 1

        return True

    def judgeSquareSum(self, c: int) -> bool:
        # 一个质数如果可以表示为两平方数之和，则被4除余1
        if c <= 2:
            return True
        if c % 4 == 3:
            return False
        if self.isPrim(c):
            return c % 4 == 1
        # 如果不是质数，求其质因数，如果其奇数重质因数中存在任一个mod4与3同余的，false
        start = 2
        while start <= c:
            if c % start == 0 and self.isPrim(start):
                i = 0
                while c > 0 and c % start == 0:
                    c = int(c / start)
                    i += 1
                if i & 1 and start % 4 == 3:
                    return False
            if self.isPrim(c):
                return c % 4 == 1
            start += 1

        return True


a = Solution()
print(a.judgeSquareSum(730663106))

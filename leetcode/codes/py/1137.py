class Solution:
    def tribonacci(self, n: int) -> int:
        a = 0
        b = 1
        c = 1
        if n == 0:
            return a
        if n == 1:
            return b
        if n == 2:
            return c
        while n > 3:
            d = a + b + c
            a = b
            b = c
            c = d
            n -= 1

        return a + b + c

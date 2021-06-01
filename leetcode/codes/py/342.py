class Solution:
    def isPowerOfFour(self, n: int) -> bool:

        return n == 1 or (n & 1 == 0 and (n >> 1) & (n >> 1 - 1) == 0)

a = Solution()
print(a.isPowerOfFour(~0))

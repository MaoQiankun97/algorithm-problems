class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        z = x ^ y
        r = 0
        while z > 0:
            z &= z-1
            r += 1

        return r

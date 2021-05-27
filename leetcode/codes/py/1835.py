from functools import reduce
from operator import xor
from typing import List


# 输入：arr1 = [1,2,3], arr2 = [6,5]
# 输出：0
# 解释：列表 = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1] ，
# 异或和 = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0 。
#   (1 AND 6) XOR (1 AND 5) XOR (2 AND 6) XOR (2 AND 5) XOR (3 AND 6) XOR (3 AND 5)
# =  (1 ^ 2 ^ 3) & (6 ^ 5)


class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:

        return reduce(xor, arr1) & reduce(xor, arr2)


a = Solution()
print(a.getXORSum([1, 2, 3], [6, 5]))

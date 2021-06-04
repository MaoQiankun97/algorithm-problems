from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        result = 0
        i = 1
        for num in nums:
            result ^= i
            result ^= num
            i += 1

        return result

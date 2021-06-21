from typing import List


class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        # 先求数组前缀和
        help = nums.copy()
        for i in range(1, help.__len__()):
            help[i] += help[i - 1]

        dict = {}
        for i in range(help.__len__()):
            if not dict.__contains__(help[i]):
                dict[help[i]] = 1
            else:
                dict[help[i]] += 1

        result = 0
        for k, v in dict.items():
            if k == goal:
                result += v
            k_1 = goal + k
            if k_1 == k:
                if v >= 2:
                    result += v * (v - 1) // 2
            else:
                if dict.__contains__(k_1):
                    result += dict[k_1] * v

        return result


a = Solution()

print(a.numSubarraysWithSum([1, 0, 1, 0, 1], goal=2))

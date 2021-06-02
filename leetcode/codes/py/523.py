from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        dp = [0] * (len(nums) + 1)

        for i in range(len(nums)):
            dp[i+1] = dp[i] + nums[i]

        dict = {}
        for i in range(len(dp)):
            t = dp[i] % k
            if dict.__contains__(t):
                if dict[t] < i - 1:
                    return True
            else:
                dict[t] = i

        return False


a = Solution()

print(a.checkSubarraySum([5, 0, 0, 0], 3))

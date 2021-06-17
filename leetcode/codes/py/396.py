from typing import List


class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        nums_sum = 0
        init_max = 0
        for i in range(len(nums)):
            nums_sum += nums[i]
            init_max += i * nums[i]

        t = init_max
        for i in range(len(nums)):
            t = t + nums_sum - nums[len(nums) - i - 1] * len(nums)
            if t > init_max:
                init_max = t

        return init_max


a = Solution()
print(a.maxRotateFunction([4, 3, 2, 6]))

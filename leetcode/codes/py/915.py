from typing import List


class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        max_arr = [0] * len(nums)
        min_arr = [1111111] * len(nums)
        for i in range(len(nums)):
            max_arr[i] = max(max_arr[i - 1] if i - 1 >= 0 else 0, nums[i])
            j = len(nums) - i - 1
            min_arr[j] = min(min_arr[j + 1] if j + 1 < len(nums) else 1111111, nums[j])
        # [1, 1, 1, 0, 6, 12]
        # [1, 1, 1, 1, 6, 12]
        # [0, 0, 0, 0, 6, 12]
        for i in range(1, len(nums)):
            if max_arr[i - 1] <= min_arr[i]:
                return i

        return -1


a = Solution()
print(a.partitionDisjoint([5, 0, 3, 8, 6]))

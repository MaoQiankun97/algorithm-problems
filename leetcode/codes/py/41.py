# 41.
# 缺失的第一个正数
# 给你一个未排序的整数数组
# nums ，请你找出其中没有出现的最小的正整数。
#
# 请你实现时间复杂度为
# O(n)
# 并且只使用常数级别额外空间的解决方案。
#
#
# 示例
# 1：
#
# 输入：nums = [1, 2, 0]
# 输出：3
# 示例
# 2：
#
# 输入：nums = [3, 4, -1, 1]
# 输出：2
# 示例
# 3：
#
# 输入：nums = [7, 8, 9, 11, 12]
# 输出：1
#
# 提示：
#
# 1 <= nums.length <= 5 * 105
# -231 <= nums[i] <= 231 - 1
from typing import List


def swap(nums: List[int], i, j):
    nums[i] = nums[i] ^ nums[j]
    nums[j] = nums[i] ^ nums[j]
    nums[i] = nums[i] ^ nums[j]


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums_len = len(nums)
        i = 0
        while i < nums_len:
            if nums[i] > nums_len or nums[i] <= 0 or nums[i] == i + 1:
                i += 1
            else:
                if nums[i] == nums[nums[i] - 1]:
                    nums[i] = 0
                    i += 1
                else:
                    swap(nums, i, nums[i] - 1)

        for i in range(nums_len):
            if nums[i] != i + 1:
                return i + 1

        return nums_len + 1


a = Solution()
print(a.firstMissingPositive([3, 4, -1, 1]))

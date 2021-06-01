from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        dict = {}
        for i in range(len(nums)):
            if dict.__contains__(nums[i]) and (i - dict[nums[i]]) <= k:
                return True
            else:
                dict[nums[i]] = i

        return False

a = Solution()

print(a.containsNearbyDuplicate(nums = [1,0,1,1], k = 1))

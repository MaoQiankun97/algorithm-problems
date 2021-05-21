from typing import List


class Solution:
    # 求最长公共子序列问题
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        nums1_len = len(nums1)
        nums2_len = len(nums2)
        # dp[i][j]表示nums1[0..i-1]和nums2[0..j-1]之间最大不相交连线是几多
        # 初始化dp[0..nums1_len][0]为0，dp[0][0..nums2_len]为0
        dp = []
        for i in range(nums1_len + 1):
            dp.append([0] * (nums2_len + 1))
        for i in range(nums1_len):
            for j in range(nums2_len):
                dp[i + 1][j + 1] = dp[i][j] + 1 if nums1[i] == nums2[j] else max(dp[i][j + 1], dp[i + 1][j])

        return dp[nums1_len][nums2_len]


a = Solution()
print(a.maxUncrossedLines([3], [3, 3, 2]))

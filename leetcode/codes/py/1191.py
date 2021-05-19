# 输入：arr = [1,-2,1], k = 5
# 输出：2

from typing import List


class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        base = 1000000007

        cur = 0
        best = 0
        for i in arr:
            cur = max(0, cur + i)
            best = max(best, cur)

        if k == 1:
            return best % base

        cur2 = cur
        best2 = best
        for i in arr:
            cur2 = max(0, cur2 + i)
            best2 = max(best2, cur2)

        if k == 2:
            return best2 % base

        arr_sum = 0
        for i in arr:
            arr_sum += i

        # 如果arr_sum小于等于0，说明重复两次就是最终的最大结果了，继续重复也不会更大（遍历到3+遍的时候，局部子数组的最大和依然是k=2的结果）
        # 如果arr_sum大于0，说明重复越多次就越多，最终结果是重复两次的结果加上(k - 2) * arr_sum
        # 因为重复两次的结果要么是arr_sum * 2，要么就是arr重复两次并去除头部或尾部的一个子数组，重复n次也同样去除相同的头部或尾部就是结果
        return (best2 + (k - 2) * arr_sum) % base if arr_sum > 0 else best2 % base

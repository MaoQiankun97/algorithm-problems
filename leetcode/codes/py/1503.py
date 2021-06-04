from typing import List


class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        min_right = n
        max_left = 0
        for l in left:
            if l > max_left:
                max_left = l
            if max_left == n:
                break
        for r in right:
            if r < min_right:
                min_right = r
            if min_right == 0:
                break

        return max(n - min_right, max_left)

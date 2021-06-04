from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        left = 0
        right = len(citations) - 1
        result = 0
        while left <= right:
            mid = (left + right) >> 1
            r = len(citations) - mid
            if citations[mid] >= r:
                result = r
                right = mid - 1
            else:
                left = mid + 1


        return result
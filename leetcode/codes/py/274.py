from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        citations.reverse()
        result = 0
        i = 0
        while i < len(citations) and citations[i] > result:
            result += 1
            i += 1

        return result
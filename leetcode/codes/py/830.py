from typing import List


class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        pre = '-'
        result = []
        cur_size = 0
        for i in range(len(s)):
            if s[i] == pre:
                cur_size += 1
            else:
                if cur_size >= 3:
                    result.append([i - cur_size, i - 1])
                cur_size = 1
                pre = s[i]

        if cur_size >= 3:
            result.append([len(s) - cur_size, len(s) - 1])

        return result
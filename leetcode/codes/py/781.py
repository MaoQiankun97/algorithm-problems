from typing import List


class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        result = 0
        list = [0] * 1001
        for a in answers:
            if a == 0:
                result += 1
                continue
            list[a + 1] += 1
            if list[a + 1] >= a + 1:
                result += a + 1
                list[a + 1] = 0

        for i in range(1001):
            if list[i] != 0:
                result += i

        return result


a = Solution()

print(a.numRabbits([0, 0, 1, 1, 1]))

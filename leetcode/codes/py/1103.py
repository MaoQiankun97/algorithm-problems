from typing import List


class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        result = [0] * num_people
        i = 0
        c = 1
        while candies > 0:
            result[i] += min(c, candies)
            candies -= c
            c += 1
            i = (i + 1) % num_people

        return result


a = Solution()
print(a.distributeCandies(7, 4))

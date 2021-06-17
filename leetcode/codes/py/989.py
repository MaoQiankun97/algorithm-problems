from typing import List


class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        k_list = []
        while k > 0:
            k_list.append(k % 10)
            k = int(k / 10)

        num.reverse()
        result = []

        i = 0
        t = 0
        while i < len(num) and i < len(k_list):
            _t = num[i] + k_list[i] + t
            result.append(int(_t % 10))
            t = int(_t / 10)
            i += 1

        while i < len(num):
            _t = num[i] + t
            result.append(int(_t % 10))
            t = int(_t / 10)
            i += 1

        while i < len(k_list):
            _t = k_list[i] + t
            result.append(int(_t % 10))
            t = int(_t / 10)
            i += 1

        if t != 0:
            result.append(t)

        result.reverse()

        return result


a = Solution()
print(a.addToArrayForm([1, 2, 0, 0], 34))

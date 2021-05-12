from typing import List

class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        result = list()
        arr_len = len(arr)
        dp = [0] * arr_len
        # dp[i] 表示从0 xor 到 i
        dp[0] = arr[0]
        for i in range(1, arr_len):
            dp[i] = dp[i-1] ^ arr[i]

        for query in queries:
            if query[0] == query[1]:
                result.append(arr[query[0]])
            else:
                if query[0] == 0:
                    result.append(dp[query[1]])
                else:
                    result.append(dp[query[0]-1] ^ dp[query[1]])

        return result

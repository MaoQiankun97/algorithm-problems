from typing import List


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        # 1 0 0 1
        # 0 1 1 0
        # 0 1 1 1
        # 1 0 1 1
        if isConnected.__len__() == 0:
            return 0
        # 广度优先搜索
        r = 0
        visited = [False] * isConnected.__len__()
        queue = [0] * 1000
        max_size = 1000
        front = 0
        rear = 0

        for i in range(isConnected.__len__()):
            if visited[i]:
                continue
            queue[rear] = i
            rear += 1
            rear %= 1000
            while front != rear:
                cur = queue[front]
                front += 1
                front %= 1000
                for j in range(isConnected.__len__()):
                    if isConnected[cur][j] and not visited[j]:
                        queue[rear] = j
                        rear += 1
                        rear %= 1000
                        visited[j] = True
            r += 1

        return r

a = Solution()
print(a.findCircleNum([[1,0,0],[0,1,0],[0,0,1]]))

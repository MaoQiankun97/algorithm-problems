from typing import List


# 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
# 输出：2
# 即从2出发遍历全图，需要时间
# 最短路径问题，使用dijkstra算法

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        if times.__len__() == 0:
            return 0
        # 先保存路径，k起点，v为以k为起点的所有路径
        dict = {}
        for i in range(n + 1):
            dict[i] = []
        for time in times:
            dict[time[0]].append(time)

        # 已计算完成的顶点
        s = [False] * (n + 1)
        INF = 99999999999
        # 路径长度
        dist = [INF] * (n + 1)
        dist[k] = 0
        # 已求出最短路径的顶点个数
        solved = 0
        while solved < n:
            cur_min = INF
            cur_min_idx = -1
            for i in range(dist.__len__()):
                if s[i]:
                    continue
                if dist[i] < cur_min:
                    cur_min = dist[i]
                    cur_min_idx = i

            if cur_min_idx == -1:
                return -1

            s[cur_min_idx] = True
            solved += 1
            edges = dict[cur_min_idx]
            for edge in edges:
                # 如果路径的另一个顶点未求得最短路径，并且从起点经过cur_min_idx到达路径的另一个顶点的长度小于当前顶点到路径的长度
                if s[edge[1]] == False and dist[edge[1]] > dist[cur_min_idx] + edge[2]:
                    dist[edge[1]] = dist[cur_min_idx] + edge[2]

        r = 0
        for i in range(1, n + 1):
            if dist[i] > r:
                r = dist[i]

        return r


a = Solution()

print(a.networkDelayTime(
    times=[[1, 2, 1]], n=2, k=2))

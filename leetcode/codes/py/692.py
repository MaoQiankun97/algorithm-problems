# 给一非空的单词列表，返回前 k 个出现次数最多的单词。
# 
# 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
# 
# 示例 1：
# 
# 输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
# 输出: ["i", "love"]
# 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
#     注意，按字母顺序 "i" 在 "love" 之前。
#  
# 
# 示例 2：
# 
# 输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
# 输出: ["the", "is", "sunny", "day"]
# 解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
#     出现次数依次为 4, 3, 2 和 1 次。
#  
# 
# 注意：
# 
# 假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
# 输入的单词均由小写字母组成。
#  
# 
# 扩展练习：
# 
# 尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。

from typing import List, Dict


class MaxRootHeap:
    heap: List
    heap_size: int

    def __init__(self):
        self.heap = []
        self.heap_size = 0

    def swapNode(self, idx_0: int, idx_1: int):
        tmp = self.heap[idx_0]
        self.heap[idx_0] = self.heap[idx_1]
        self.heap[idx_1] = tmp

    def adjustDown(self, adjustIdx: int):
        # 堆中最后一个双亲结点
        lastParentIdx = (self.heap_size >> 1) - 1
        # 如果要调整的结点不是双亲结点，即待调整结点下标在最后一个双亲结点后面，则无需调整
        if adjustIdx > lastParentIdx:
            return
        # 求出待调整结点的孩子结点的最大值
        adjustIdxLeftChildIdx = (adjustIdx << 1) + 1
        adjustIdxRightChildIdx = (adjustIdx << 1) + 2
        max_child_val = self.heap[adjustIdxLeftChildIdx][1]
        max_child_idx = adjustIdxLeftChildIdx
        if adjustIdxRightChildIdx < self.heap_size and (self.heap[adjustIdxRightChildIdx][1] >
                                                        self.heap[adjustIdxLeftChildIdx][1] or (
                                                                self.heap[adjustIdxRightChildIdx][1] ==
                                                                self.heap[adjustIdxLeftChildIdx][1] and
                                                                self.heap[adjustIdxRightChildIdx][0] <
                                                                self.heap[adjustIdxLeftChildIdx][0])):
            max_child_val = self.heap[adjustIdxRightChildIdx][1]
            max_child_idx = adjustIdxRightChildIdx
        # 孩子结点都不比待调整结点大，无需调整
        if max_child_val < self.heap[adjustIdx][1]:
            return
        if max_child_val == self.heap[adjustIdx][1] and self.heap[max_child_idx][0] > self.heap[adjustIdx][0]:
            return

        # 否则交换最大孩子结点和待调整结点，然后继续向下调整
        self.swapNode(adjustIdx, max_child_idx)
        self.adjustDown(max_child_idx)


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        dict = {}
        for word in words:
            if dict.__contains__(word):
                dict[word] += 1
            else:
                dict[word] = 1

        heap = MaxRootHeap()
        for word in dict.keys():
            frequency = dict[word]
            heap.heap.append((word, frequency))
            heap.heap_size += 1

        i = (heap.heap_size >> 1) - 1
        while i >= 0:
            heap.adjustDown(i)
            i -= 1

        result = []
        while k > 0:
            heap.swapNode(0, heap.heap_size - 1)
            result.append(heap.heap[heap.heap_size - 1][0])
            heap.heap_size -= 1
            k -= 1
            heap.adjustDown(0)

        return result


a = Solution()
re = a.topKFrequent(["i", "love", "leetcode", "i", "love", "coding"], 3)
for r in re:
    print(r, end=', ')

from typing import List


class MaxHeap:
    """
    大顶堆.
    """

    def __init__(self, nums: List[int]):
        self.heap_data = nums.copy()
        self.heap_size = nums.__len__()
        i = self.heap_size - 1
        while i >= 0:
            self.adjustDown(i)
            i -= 1

    def swap(self, i: int, j: int):
        if i == j:
            return
        self.heap_data[i] = self.heap_data[i] ^ self.heap_data[j]
        self.heap_data[j] = self.heap_data[i] ^ self.heap_data[j]
        self.heap_data[i] = self.heap_data[i] ^ self.heap_data[j]

    def adjustDown(self, i: int):
        """
        向下调整.
        """
        if i > (self.heap_size >> 1) - 1:
            return

        child_max = self.heap_data[2 * i + 1]
        child_max_idx = 2 * i + 1
        if 2 * i + 2 < self.heap_size and child_max < self.heap_data[2 * i + 2]:
            child_max = self.heap_data[2 * i + 2]
            child_max_idx += 1

        if self.heap_data[i] >= child_max:
            return

        self.swap(i, child_max_idx)
        self.adjustDown(child_max_idx)

    def adjustUp(self):
        """
        向上调整.
        """

    def getMax(self):
        """
        获取堆中最大的值
        :return:
        """
        return self.heap_data[0]

    def findOne(self, idx: int, val: int) -> int:
        if idx >= self.heap_size or self.heap_data[idx] < val:
            return -1

        if self.heap_data[idx] == val:
            return idx

        t = self.findOne(idx * 2 + 1, val)
        if t != -1:
            return t
        t = self.findOne(idx * 2 + 2, val)
        if t != -1:
            return t

        return -1

    def replaceOne(self, val: int, new_val: int):
        """
        替换一个值为新值，并将堆调整好
        :return:
        """
        val_idx = self.findOne(0, val)
        if self.heap_data[val_idx] == new_val:
            return
        self.heap_data[val_idx] = new_val
        # # self.swap(val_idx, 0)
        # # self.adjustDown(0)
        # i = self.heap_size - 1
        # while i >= 0:
        #     self.adjustDown(i)
        #     i -= 1

# TODO
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums
        heap = MaxHeap(nums[:k])
        i = k
        result = []
        result.append(heap.getMax())
        while i < len(nums):
            # 如果淘汰的是最大值, 堆需要重新调整
            heap.replaceOne(nums[i - k], nums[i])
            if nums[i - k] == heap.getMax():
                while i >= 0:
                    heap.adjustDown(i)
                    i -= 1
            result.append(heap.getMax())
            i += 1

        return result

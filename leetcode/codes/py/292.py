class Solution:
    def canWinNim(self, n: int) -> bool:
        # 1 直接 true
        # 2 直接 true
        # 3 直接 true
        # 4 只能 false
        # 5 可以只选1个，然后转为!canWinNim(4) = true
        # 6 可以只选2个，然后转为!canWinNim(4) = true
        # 7 可以先选3个，然后转为!canWinNim(4) = true
        # 8 不管选几个，都会转为!canWinNim([5|6|7])问题 false
        return n % 4 != 0


a = Solution()
print(a.canWinNim(4312232))

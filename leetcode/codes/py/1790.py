class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        def_num = 0
        def1 = {}
        def2 = {}

        for i in range(len(s1)):
            if s1[i] == s2[i]:
                continue

            def_num += 1
            if def_num > 2:
                return False
            def1[s1[i]] = 1
            def2[s2[i]] = 1

        if not def1.__eq__(def2):
            return False

        return True

a = Solution()

print(a.areAlmostEqual('bank', 'kanb'))
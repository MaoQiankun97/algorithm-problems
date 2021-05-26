class Solution:
    def reverseParentheses(self, s: str) -> str:
        result = self.help(s, 0)[1]

        return result

    def help(self, s: str, idx: int) -> (int, str):
        cur_str = ''
        if idx >= len(s):
            return idx + 1, cur_str

        while idx < len(s):
            if s[idx] == '(':
                r = self.help(s, idx + 1)
                idx = r[0]
                t = r[1]
                l = list(t)
                l.reverse()
                t = ''.join(l)
                cur_str += t
            else:
                if s[idx] == ')':
                    return idx, cur_str
                else:
                    cur_str += s[idx]
            idx += 1

        return idx, cur_str


a = Solution()
print(a.reverseParentheses("a(bcdefghijkl(mno)p)q"))

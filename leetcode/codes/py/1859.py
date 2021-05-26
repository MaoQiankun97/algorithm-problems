class Solution:
    def sortSentence(self, s: str) -> str:
        dict = {}
        cur_word = ''
        s += ' '
        for _ in s:
            if _ == ' ':
                dict[int(cur_word[len(cur_word) - 1])] = cur_word[:-1]
                cur_word = ''
            else:
                cur_word += _

        r = ''
        for i in range(1, 10):
            if dict.__contains__(i):
                r += dict[i]
                r += ' '
            else:
                break

        return r[:-1]


a = Solution()
print(a.sortSentence("is2 sentence4 This1 a3"))

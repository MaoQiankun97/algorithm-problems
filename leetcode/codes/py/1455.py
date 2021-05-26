class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(' ')
        for i in range(len(words)):
            word = words[i]
            if word.startswith(searchWord):
                return i + 1

        return -1
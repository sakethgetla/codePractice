
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len( word2 ) != len(word1):
            return False

        if (word1[0] != word2[0]):
            # swap
            for i in range(1, len(word2)):
                if ( )



        # if:
        return True if len(word1) == 1 and word1[0] == word2[0] else self.closeStrings(word1[1:], word2[1:])


s = Solution()
w1 = "abc"
w2 = "bca"
o = s.closeStrings(w1, w2)
print(o)

        

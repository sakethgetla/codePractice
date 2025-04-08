class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i = 0
        j = 0
        out = ''
        while i < len( word1 ) or j < len(word2):
            if (i < len(word1)):
                out += word1[i]
                i += 1
            if (j < len(word2)):
                out += word2[j]
                j += 1
            # if ((j < i and j < len(word2)) or i == len(word1)):
            #     # out[i+j] = word2[j]
            #     out += word2[j]
            #     j+=1
            # else :
            #     out += word1[i]
            #     i+=1
        return out


c = Solution()
a = 'abcdefg'
b = '123'
d = c.mergeAlternately(b,a)

print(d)

       

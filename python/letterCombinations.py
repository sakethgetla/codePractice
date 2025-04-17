from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letters = [['a', 'b', 'c'],
        ['d', 'e', 'f'],
        ['g', 'h', 'i'],
        ['j', 'k', 'l'],
        ['m', 'n', 'o'],
        ['p', 'q', 'r', 's'],
        ['t', 'u', 'v'],
        ['w', 'x', 'y', 'z']]
        c = []
        # print (len(digits) )
        if len(digits)== 0:
            return []
        elif len(digits) > 1:
            # print (digits[0:-1])
            c = self.letterCombinations(digits[0:-1])
            # print ('c',c)
        else:
            # print ( int(digits[-1]) -2 )
            # print (letters[ int(digits[-1]) -2 ])
            return letters[ int(digits[-1]) -2 ]

        out = []
        for i in c:
            # print ( int(digits[-1]) -2 , letters[ int(digits[-1]) -2 ] )
            for j in letters[ int(digits[-1]) -2 ] :
                out.append(i + j)
        # print (a)
        # print (b)
        # print (c)
        return out

s = Solution()
# s.letterCombinations('2')
# o = s.letterCombinations('23')
# o = s.letterCombinations('92')
o = s.letterCombinations('')
print(o)

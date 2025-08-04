from typing import List

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        indx = []
        gp1= True if groups[0] == 1 else False
        for i in range(len(groups)):
            if gp1 == True and groups[i] == 1:
                indx.append(i)
                gp1 = False
            elif gp1 == False and groups[i] == 0:
                indx.append(i)
                gp1 = True
        return [ words[i] for i in indx]



        
s = Solution()
n = ["a","b","c","d"]
g = [1,0,1,1]
o = s.getLongestSubsequence(n,g)
print (n, g, o)
assert o == ['a','b','c']

n = ['e', 'a', 'b']
g = [0,0,1]
o = s.getLongestSubsequence(n,g)
print (n, g, o)
assert o == ['e','b']

n = ['e', 'a', 'b']
g = [0,0,1]
o = s.getLongestSubsequence(n,g)
print (n, g, o)
assert o == ['e','b']


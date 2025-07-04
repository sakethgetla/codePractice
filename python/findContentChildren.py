from typing import List

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        i = 0
        # for c in g:
        print(g, s)
        content = 0
        for j in range(len(g)):
            while i < len(s) and g[j] > s[i]:
                i += 1
            if i < len(s) and g[j] <= s[i]:
                i += 1
                content += 1
            # print(g[j], i)
            # if i == len(s):
            #     return j
            # if i >= len(s)-1:
            #     # return int(j)
            #     # return j +1-1
            #     return j
            # # if i < len(s) and g[j] <= s[i]:
            #
        return content



        
s = Solution()
g = [1,2,3]
n = [1,1]
o = s.findContentChildren(g,n)
print (g,n, o)
assert o == 1

g = [1,2,3]
n = [1,8]
o = s.findContentChildren(g,n)
print (g,n, o)
assert o == 2

g = [1,2,3]
n = [79,22,33,22, 1]
o = s.findContentChildren(g,n)
print (g,n, o)
assert o == 3

g = [1,2,3]
n = []
o = s.findContentChildren(g,n)
print (g,n, o)
assert o == 0

g = [1,2,3]
n = [79, 1]
o = s.findContentChildren(g,n)
print (g,n, o)
assert o == 2


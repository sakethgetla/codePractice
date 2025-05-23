from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn = float('inf')
        mxdiff = 0
        for p in prices:
            if mxdiff < p-mn :
                mxdiff = p-mn
            if mn > p:
                mn = p

        return mxdiff

s = Solution()
p = [7,1,5,3,6,4]
o = s.maxProfit(p)
print(p, o)
assert o == 5

p = [7,6,4,3,1]
o = s.maxProfit(p)
print(p, o)
assert o == 0

p = [7,1,5,3,6,4]
o = s.maxProfit(p)
print(p, o)
assert o == 5


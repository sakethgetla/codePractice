from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        alt = 0
        maxAlt = 0
        for g in gain:
            alt += g
            maxAlt = max(maxAlt, alt)
        return maxAlt


# a = [1,12,-5,-6,50,3]
# a = [-5,1,5,0,-7]
a = [-4,-3,-2,-1,4,3,2]
c = Solution()
d = c.largestAltitude(a)
print(a, d)


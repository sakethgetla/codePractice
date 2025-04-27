from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        low = 0
        high = len(height)-1
        maxA = 0
        while low < high:
            currArea = min(height[low], height[high]) * ( high-low )
            maxA = max(maxA, currArea)
            if height[low] < height[high]:
                low +=1
            else :
                high -=1
        return maxA

s = Solution()
# height = [1,8,6,2,5,4,8,3,7]
height = [1,1]
o = s.maxArea(height)
print(height, o)
